from math import *

t = int(input())

for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    m = max(*l)
    f = False
    j = 0
    for i in range(0, n):
        if i != 0 and i != n-1:
            if l[i] == m and l[i-1] < l[i] or l[i+1] < l[i]:
                j = i
                f = True
                break
        elif i == 0 and l[i] == m and l[i+1] < l[i]:
            j = i
            f = True
            break
        elif i == n - 1 and l[i] == m and l[i-1] < l[i]:
            j = i
            f = True
            break
    if not f:
        print(-1)
    else:
        print(j + 1)