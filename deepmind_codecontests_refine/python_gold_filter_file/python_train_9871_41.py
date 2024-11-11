# coding: utf-8

import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)

powof2 = lambda x: len("{:b}".format(x))

def f2(n, h, a):
    p = powof2(n)
    N = 2 ** p
    segt = [0] * (2 * N - 1)

    def getmax(a, b, i = 0, l = 0, r = N - 1):
        if r <= a or b <= l:
            return(0)
        if a <= l and r <= b:
            return(segt[i])
        i1 = 2 * i + 1
        i2 = i1 + 1
        lr = (l + r) // 2
        lmax = getmax(a, b, i1, l, lr)
        rmax = getmax(a, b, i2, lr, r)
        return(lmax if lmax > rmax else rmax)

    def setmax(i, v):
        si = i + N - 1
        segt[si] = v
        while si > 0:
            si = (si - 1) // 2
            si1 = 2 * si + 1
            si2 = si1 + 1
            segt[si] = segt[si1] if segt[si1] > segt[si2] else segt[si2]

    for i in range(1, n + 1):
        m = getmax(0, h[i])
        setmax(h[i], m + a[i])

    return(getmax(0, n))

n = int(input()) # 1 <= n <= 2 x 10^5
h = [0] + list(map(int, input().split()))
a = [0] + list(map(int, input().split()))
print(f2(n, h, a))
