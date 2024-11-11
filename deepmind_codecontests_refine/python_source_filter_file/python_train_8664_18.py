from math import *

mod = 1000000007

n, m = map(int, input().split())
a = [int(i) for i in input().split()]
if sum(a) < n:
    print(-1)
else:
    x = [-1] * n
    p = [0] * m
    p[-1] = 0
    d = a[-1]
    for i in range(d):
        x[i] = m - 1
        
    cs = sum(a) - a[-1]
    c = m - 1
    for i in range(m - 2, -1, -1):
        #print(i)
        if d > n:
            break
        cd = max(1, min(n - c - d + 1, a[i]))
        if a[i] - cd > d:
            cd = a[i] - d
        #print(cd, n, c, d, a[i])
        p[i] = d + cd - a[i] + 1
        for j in range(d, min(n, d + cd)):
            if x[j] < 0:
                x[j] = i
        d += cd
        c -= 1
        #print()
    #print(x)
    s = set()
    for i in x:
        if i >= 0 and i not in s:
            s.add(i)

    if len(s) == m:
        print(*p)
    else:
        print(-1)
