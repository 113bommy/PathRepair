N = int(input())
P = map(int, input().split())

Kcost = [min(row, N - 1 - row, clm, N - 1 - clm) for row in range(N) for clm in range(N)]

Sitting = [1] * (N * N)
Kcount = 0


def Kcheck(qsn, cdsn):
    if Kcost[cdsn] > Kcost[qsn] + Sitting[qsn]:
        Kcost[cdsn] = Kcost[qsn] + Sitting[qsn]
        queue.append(cdsn)


for sn in P:
    csn = sn - 1
    Kcount += Kcost[csn]
    Sitting[csn] = 0
    queue = [csn]

    while queue:
        qsn = queue.pop()
        div, mod = divmod(qsn, N)
        if mod: Kcheck(qsn, qsn - 1)
        if mod != N - 1: Kcheck(qsn, qsn + 1)
        if div: Kcheck(qsn, qsn - N)
        if div != N - 1: Kcheck(qsn, qsn + N)

print(Kcount)
