t = int(input())

for i in range(t):
    input()
    m, k = [int(l) for l in input().split()]
    a = [int(j) for j in input().split()]
    upset = -1
    unknown = 0
    unknownBeforeUpset = 0
    ti, r = [], []
    for i1 in range(m-1):
        n = input().split()
        ti.append(int(n[0]))
        r.append(int(n[1]))
        ti[i1] -= 1

        if r[i1] == 1 and upset == -1:
            upset = i1

        if ti[i1] != -1:
            a[ti[i1]] -= 1
        else:
            unknown+=1
            if upset == -1:
                unknownBeforeUpset+=1

    st = ["N" for j in range(k)]
    if upset == -1:
        for j in range(k):
            if a[j] <= unknown:
                st[j] = "Y"
    else:
        usedAfter = [False for i in range(k)]
        for j in range(upset, m-2):
            if ti[j] != -1:
                usedAfter[j] = True
        minFirstFinished = -1
        for j in range(k):
            if not usedAfter[j] and unknownBeforeUpset >= a[j]:
                st[j] = 'Y'
                if minFirstFinished == -1 or minFirstFinished > a[j]:
                    minFirstFinished = j
        if minFirstFinished != -1:
            restUnknown = unknown - a[minFirstFinished]
            for j in range(k):
                if a[j] <= restUnknown:
                    st[j] = 'Y'

    print("".join(st))