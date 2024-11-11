n, m, k, l = map(int, input().split())
x = (l + m - 1) // m
print(x  if x * m <= n else -1)