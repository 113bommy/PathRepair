from math import gcd
def facts(n):
    ans = []
    while n%2 == 0:
        ans.append(2)
        n = n//2
    for i in range(3, int(n**0.5+7), 2):
        while n%i == 0:
            ans.append(i)
            n = n // i
    if n > 2:
        ans.append(n)
    ans.sort()
    return ans
t = int(input())
for _ in range(t):
    p, q = [int(p) for p in input().split()]
    if p < q:
        print(p)
        continue
    elif p == q:
        ok = False
        if q%2 == 0:
            print(p//2)
            continue
        else:
            for i in range(3, int(q**0.5)+1, 2):
                if q%i == 0:
                    ok = True
                    print(max(q//i, i))
                    break
        if not ok:
            print(1)
    elif p%q != 0:
        print(p)
        continue
    elif p%q == 0:
        f1 = facts(q)
        t = p//q
        ans = 1
        for i in range(len(f1)):
            ele = p
            while ele%f1[i] == 0:
                ele = ele // f1[i]
                if ele%q:
                    ans = max(ans, ele)
                    break
        print(ans)
