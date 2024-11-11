import bisect
while True:
    n = int(input())
    if n == 0:
        break
    tc = sorted([int(input()) for _ in range(n)])
    hc = sorted([v for v in range(1, 2*n+1) if v not in tc])
    ba = []
    flag = True
    while tc and hc:
        if len(ba) == 0:
            try:
                if flag:
                    tmp = tc.pop(0)
                    flag = False
                else:
                    tmp = hc.pop(0)
                    flag = True
            except IndexError:
                pass
            ba = [tmp]
            continue

        last_card = ba[-1]
        if flag:
            x = bisect.bisect_left(tc, last_card)
            flag = False
            try:
                tmp = tc.pop(x)
            except IndexError:
                ba = []
                continue
        else:
            x = bisect.bisect_left(hc, last_card)
            flag = True
            try:
                tmp = hc.pop(x)
            except IndexError:
                ba = []
                continue
        ba.append(tmp)
    print(len(tc))
    print(len(hc))