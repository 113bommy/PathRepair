#!/usr/bin/env python3

t = int(input())
for _ in range(t):
    n = int(input())
    a = [int(i) for i in input().split()]
    # s = set(a)
    s = [0] * (n + 1)
    for a_i in a:
        s[a_i] += 1
    c = 0
    for i in range(n - 1):
        s_i = a[i]
        for j in range(i + 1, n):
            s_i += a[j]
            if s_i > n:
                break
            # if s_i in s:
            if s[s_i] > 0:
                c += s[s_i]
                s[s_i] = 0
    print(c)
