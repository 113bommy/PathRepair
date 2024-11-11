for _ in range(int(input())):
    L, R = 0, 10 ** 9 + 1
    for _ in range(int(input())):
        l, r = map(int, input().split())
        L = min(L, l)
        R = max(R, r)
    print(max(0, R - L))