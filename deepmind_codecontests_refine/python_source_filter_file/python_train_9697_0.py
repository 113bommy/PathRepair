#!/usr/bin/python3.7

import sys

mod = 998244353

n, k = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]

ub = [0 for i in range(n)]
b = [[0, 0] for i in range(n)]
ub[0] = 1
b[0] = [0, 1]
for i in range(1, n):
    ub[i] = ub[i - 1] * (k - 1) % mod
    sb = b[i - 1][0] + b[i - 1][1] * (k - 1) % mod
    if sb >= mod:
        sb -= mod
    for j in range(2):
        b[i][j] = sb - b[i - 1][j]
        if b[i][j] < 0:
            b[i][j] += mod

ans = 1
for arr in [a[::2], a[1::2]]:

    for i in range(1, len(arr)):
        if (arr[i] != -1) and (arr[i] == arr[i - 1]):
            print(0)
            sys.exit()

    cur = -1
    for i, x in enumerate(arr):
        if x == -1:
            continue
        cnt = i - cur - 1
        if cnt > 0:
            if cur == -1:
                ans = (ans * ub[cnt - 1] * (k - 1)) % mod
            else:
                s = b[cnt - 1][0] + b[cnt - 1][1] * (k - 1) % mod
                if s >= mod:
                    s -= mod
                if x == arr[cnt]:
                    s -= b[cnt - 1][0]
                else:
                    s -= b[cnt - 1][1]
                if s < 0:
                    s += mod
                ans = ans * s % mod
        cur = i
    if cur == -1:
        ans = (ans * ub[len(arr) - 1] * k) % mod
    elif cur < len(arr) - 1:
        cnt = len(arr) - cur - 1
        s = b[cnt - 1][0] + b[cnt - 1][1] * (k - 1) % mod
        if s >= mod:
            s -= mod
        ans = ans * s % mod


print(ans)
