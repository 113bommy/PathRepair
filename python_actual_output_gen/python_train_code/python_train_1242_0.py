n, m = map(int, input().split())
print(m - 1 if m - 1 >= n - m else m + 1)