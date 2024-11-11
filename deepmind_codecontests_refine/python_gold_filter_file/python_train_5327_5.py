for _ in [0] * int(input()):
    n, s, t = map(int, input().split())
    print(1 if (s+t) // n == 2 else n - min(s, t) + 1)