t = int(input())

for _ in range(t):
    p, f = map(int, input().split())
    cnts, cntw = map(int, input().split())
    s, w = map(int, input().split())

    p, f = max(p, f), min(p, f)
    if w < s:
        cnts, s, cntw, w = cntw, w, cnts, s

    sNo = p // s + f // s
    sNo = min(sNo, cnts)

    best = sNo

    for i in range(sNo + 1):
        if p // s < i:
            break
        if f // s < sNo - i:
            continue
        remainingP = p - s * i
        remainingF = f - (sNo - i) * s

        additionalW = remainingP // w + remainingF // w
        additionalW = min(additionalW, cntw)

        best = max(best, sNo + additionalW)

    print(best)
