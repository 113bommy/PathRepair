from functools import reduce
from collections import defaultdict
N = int(input())
A = list(map(int,input().split()))

r = reduce(lambda x,y : x^y , A[2:],0)

a,b = A[:2]

def answer(ta,tb,tr):
    for i in range(ta):
        if (ta-i)^(tb+i) == tr:
            ans = i
            break
    else:
        ans = -1
    return ans

def solve(a,b,r):
    orga = a

    ans = 0
    l = max(map(lambda x : len(bin(x)), [a,b,r])) - 2
    cand = {(a,b,r):0}
    for i in range(l):
        temp = defaultdict(lambda : 10**10)
        for (a,b,r),s in cand.items():
            x,y,z = a%2,b%2,r%2
            if not x^y == z:
                continue
            else:
                if s < temp[(a//2,b//2,r//2)]:
                    temp[(a//2,b//2,r//2)] = s
                a -= 1
                b += 1
                if a < 0:
                    continue
                s += (1<<i)
                if s < temp[(a//2,b//2,r//2)]:
                    temp[(a//2,b//2,r//2)] = s
        cand = temp

    if not (0,0,0) in cand:
        ans = -1
    else:
        ans = cand[(0,0,0)]
        if ans == orga:
            ans = -1
    return ans

print(answer(a,b,r))
