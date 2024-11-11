# Fast IO (be careful about bytestring, not on interactive)

import os,io
input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

INF = 10 ** 20

for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    MINDP = [INF,INF,INF,INF,INF]
    MAXDP = [INF,INF,INF,INF,INF]
    for i in range(n):

        if MINDP[3] != INF and (MINDP[4] == INF or min(MINDP[3] * a[i], MAXDP[3] * a[i]) < MINDP[4]):
            MINDP[4] = min(MINDP[3] * a[i], MAXDP[3] * a[i])
        if MAXDP[3] != INF and (MAXDP[4] == INF or max(MINDP[3] * a[i], MAXDP[3] * a[i]) > MAXDP[4]):
            MAXDP[4] = max(MINDP[3] * a[i], MAXDP[3] * a[i])

        if MINDP[2] != INF and (MINDP[3] == INF or min(MINDP[2] * a[i], MAXDP[2] * a[i]) < MINDP[3]):
            MINDP[3] = min(MINDP[2] * a[i], MAXDP[2] * a[i])
        if MAXDP[2] != INF and (MAXDP[3] == INF or max(MINDP[2] * a[i], MAXDP[2] * a[i]) > MAXDP[3]):
            MAXDP[3] = max(MINDP[2] * a[i], MAXDP[2] * a[i])

        if MINDP[1] != INF and (MINDP[2] == INF or min(MINDP[1] * a[i], MAXDP[1] * a[i]) < MINDP[2]):
            MINDP[2] = min(MINDP[1] * a[i], MAXDP[1] * a[i])
        if MAXDP[1] != INF and (MAXDP[2] == INF or max(MINDP[1] * a[i], MAXDP[1] * a[i]) > MAXDP[2]):
            MAXDP[2] = max(MINDP[1] * a[i], MAXDP[1] * a[i])

        if MINDP[0] != INF and (MINDP[1] == INF or min(MINDP[0] * a[i], MAXDP[0] * a[i]) < MINDP[1]):
            MINDP[1] = min(MINDP[0] * a[i], MAXDP[0] * a[i])
        if MAXDP[0] != INF and (MAXDP[1] == INF or max(MINDP[0] * a[i], MAXDP[0] * a[i]) > MAXDP[1]):
            MAXDP[1] = max(MINDP[0] * a[i], MAXDP[0] * a[i])

        if MINDP[0] == INF or MINDP[0] > a[i]:
            MINDP[0] = a[i]
        if MAXDP[0] == INF or MAXDP[0] < a[i]:
            MAXDP[0] = a[i]

    print(MAXDP[4])
