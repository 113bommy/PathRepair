import sys

input = lambda: sys.stdin.readline().rstrip()

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    ans1 = 0
    a1 = 0
    ans2 = 0
    a2 = 0
    c1 = 0
    c2 = 0
    m = 0
    g = 0
    while c1 != n:
        if a[c1] > 0 and a1 % 2 == 0:
            a1 += 1
            m = a[c1]
            ans1 += g
            g = 0
        if a[c1] > 0 and a1 % 2 == 1:
            if a[c1] > m:
                m = a[c1]
        if a[c1] < 0 and a1 % 2 == 1:
            a1 += 1
            ans1 += a[c1]
            ans1 += m
            m = 0
        if a[c1] < 0 and a1 % 2 == 0:
            if a[c1] > g:
                g = a[c1]
        c1 += 1
    ans1 += m
    ans1 += g
    m, g = 0, 0
    while c2 != n:
        if a[c2] < 0 and a2 % 2 == 0:
            g = a[c2]
            a2 += 1
            ans2 += m
            m = 0
        if a[c2] > 0 and a2 % 2 == 1:
            a2 += 1
            m = a[c2]
            ans2 += g
            g = 0
        if a[c2] > 0 and a2 % 2 == 0:
            if m < a[c2]:
                m = a[c2]
        if a[c2] < 0 and a2 % 2 == 1:
            if g < a[c2]:
                g = a[c2]
        c2 += 1
    ans2 += g
    ans2 += m
    if a1 > a2:
        print(ans1)
    elif a2 > a1:
        print(ans2)
    else:
        print(min(ans1, ans2))
