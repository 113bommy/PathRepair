"https://codeforces.com/contest/1328/problem/B"
import collections, heapq, itertools, math
groupby = itertools.groupby
rs  = lambda: input()
ri  = lambda: int(input())
rm  = lambda: map(int, input().split())
rai = lambda: [int(x) for x in input().split()]

def solve(n,k):
    S = ['a' for x in range(n)]
    i=0
    while True:
        if i*(i+1)>=2*k:
            break
        i+=1
    i-=1
    #print('i',i)
    S[-2-i]='b'
    S[i*(i+1)//2-k]='b'
    return ''.join(S)  
        
for t in range(1, 1 + ri()):
    n, k = rm()
    print(n,k)
    ans = solve(n,k)
    print ("{}".format(ans))