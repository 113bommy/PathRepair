
for _ in range(int(input())):
    n = int(input())
    c = list(map(int, input().split()))
    d = {}
    for cc in c:
        if cc not in d:
            d[cc] = 1
        else:
            d[cc] += 1
    mn = 999999999
    mc = None
    for dd in d:
        if d[dd] < mn:
            mn = d[dd]
            mc = dd
    # print(mc, mn)
    if mn == 1:
        count = 0
        for dd in d:
            count += d[dd] // 2 + d[dd] % 2
        print(count)
        continue
    for s in range(mn, 1, -1):
        b = False
        count = 0
        for dd in d:
            x = d[dd] // s
            if d[dd] % s != 0:
                x += 1
            count += x
            if not ((s - 1) * x <= d[dd] <= s * x):
                b = True
                break
        if not b:
            print(count)
            break