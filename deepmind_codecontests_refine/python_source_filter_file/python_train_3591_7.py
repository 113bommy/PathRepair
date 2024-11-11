n, m = map(int, input().split())
print(max(m + 1, n) if n - m > m - 1 else max(m - 1, 1))