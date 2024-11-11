for _ in [0]*int(input()):
    n, p, k = map(int, input().split())
    a = sorted(list(map(int, input().split())))
    a.append(10001)
    n += 1
    P = p
    gifts = 0
    #print(a)
    for i in range(1, n, 2):
        if P - a[i] < 0:
            if P - a[i-1] >= 0:
                P -= a[i-1]
                gifts += 1
            break
        P -= a[i]
        gifts += 2
    gifts_ = min(gifts, 1)
    p -= a[0]
    for i in range(2, n, 2):
        if p - a[i] < 0:
            if p - a[i-1] >= 0:
                p -= a[i-1]
                gifts_ += 1
            break
        p -= a[i]
        gifts_ += 2
    print(max(gifts, gifts_))