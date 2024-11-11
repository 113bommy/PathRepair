# -*- coding: UTF-8 -*-

def com(x, y):
    lx, ly = len(x), len(y)
    now = 0
    for xx in x:
        if xx == y[now]:
            now += 1
        if now == ly:
            break
    return lx-now+ly-now

import sys
input = sys.stdin.readline

power = []
for i in range(60):
    power.append(str(2**i))

t = int(input())
for _ in range(t):
    n = input().rstrip('\n')
    ans = 20
    for i in power:
        ans = min(ans, com(n, i))
    print(ans)
