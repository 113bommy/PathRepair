for _ in range(int(input())):
    n, m, k = map(int, input().split())
    x = max(n // k, m)
    y = (m - x - 1) // (k-1) + 1
    print(x - y)