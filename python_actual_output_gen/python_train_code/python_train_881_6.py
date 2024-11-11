for _ in range(int(input())):
    a, b, n, S = map(int, input().split())
    kBigCoins = round(S/n)
    if a >= kBigCoins:
        if S - kBigCoins*n <= b:
            print("YES")
        else:
            print("NO")
    else:
        if S-(a*n) <= b:
            print("YES")
        else:
            print("NO")
