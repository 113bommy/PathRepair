#!/usr/bin python3
# -*- coding: utf-8 -*-

n, m, v, p = map(int, input().split())
a = list(map(int, input().split()))
a.sort(reverse = True)

def f(x):
    if x < p:
        return True
    if a[p-1] > a[x] + m:
        return False
    else:
        res = m * v
        res -= m * (n-x)
        res -= m * (p-1)
        for i in range(p-1, x):
            res -= min(m, max(0,a[x]+m-a[i]))
        return res < 0

ok = 0
ng = n
while ng - ok > 1:
    nw = (ok+ng) // 2
    if f(nw):
        ok = nw
    else:
        ng = nw
print(ng)
