for _ in range(int(input())):
    p, q = map(int, input().split())
    if p % q != 0:
        print(p)
        continue
    pr = {}
    i = 2
    while i*i <= q:
        if q % i == 0:
            x = 0
            while q % i == 0:
                q //= i
                x += 1
            pr[i] = x
        i += 1
    if q != 1:
        pr[q] = 1

    res = 1
    for k in pr:
        v = pr[k]
        pp = p
        x = 0
        while pp % k == 0:
            pp //= k
            x += 1
        res = max(res, p//k**(x-(v-1)))
    print(res)
