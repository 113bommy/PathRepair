for _ in range(int(input())):
    b, p, f = map(int, input().split())
    h, c = map(int, input().split())
    profit = 0
    # buns = b
    if c > h:
        profit += min(b//2, f) * c
        b -= (profit//c) * 2
        profit += min(b // 2, p) * h
    else:
        profit += min(b // 2, f) * h
        b -= (profit // h) * 2
        profit += min(b // 2, p) * c
    print(profit)