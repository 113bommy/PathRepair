for _ in range(int(input())):
    n, x, a, b = map(int, input().split())
    print(min(n - 1, abs(a - b) + x))
