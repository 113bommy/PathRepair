n, m = map(int, input().split())
if 1 == n:
    print(1)
else:
    print(1 / n + (n - 1) * (m - 1) / (n * (n * m - 1)))
