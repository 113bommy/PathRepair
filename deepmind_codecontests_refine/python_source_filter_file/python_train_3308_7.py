#!/usr/bin/env python3
import sys

#solve
def solve():

    input = sys.stdin.buffer.readline
    LI = lambda: map(int, input().split())
    II = lambda: int(input())
    n = II()
    vw = [[]] * n
    M = 10 ** 5 + 1
    M0 = [0] * M
    XX = 1 << 9
    d = [[]] * XX
    d[0] = M0

    for i in range(1, min(XX, n + 1)):
        v, w = LI()
        vw[i - 1] = (v, w)
        di = d[i // 2][:]
        for j in range(M - 1, w - 1, -1):
            if di[j] < di[j - w] + v:
                di[j] = di[j - w] + v
        d[i] = di

    for i in range(XX, n + 1):
        v, w = LI()
        vw[i - 1] = (v, w)

    Vv = [i.bit_length() for i in range(1 << 18)]
    n = [pow(2, i) for i in range(18)]
    lentl = [i - 9 for i in range(19)]
    maskset = [[]] * n[9]

    for i in range(1, 10):
        for mask in range(n[i - 1], n[i]):
            a = mask & -mask
            b = Vv[a] - 1
            maska = mask - a
            maskset[mask - 1] = (mask, b, maska)

    for _ in range(II()):
        V, L = LI()

        if V < XX:
            print(d[V][L])
            continue

        n2 = lentl[Vv[V]]
        vw2 = [None] * n2

        for i in range(n2):
            vw2[i] = (vw[V - 1][0], vw[V - 1][1])
            V //= 2

        lw = [0] * n[n2]
        lv = [0] * n[n2]
        dv = d[V]
        ans = dv[L]

        for i in range(n[n2] - 1):
            mask, b, maska = maskset[i]
            v, w = vw2[b]
            ww = lw[maska] + w
            Lww = L - ww
            lw[mask] = ww
            if Lww < 0: continue
            vv = lv[maska] + v
            lv[mask] = vv
            tmp = dv[Lww] + vv
            if tmp > ans:
                ans = tmp
        print(ans)
    return

if __name__ == "__main__":
    solve()
