n, a, b, c, d = map(int, input().split())

min_sum = max(a + b, a + c, b + d, c + d) + 1
max_sum = min(a + b, a + c, b + d, c + d) + n

print((max_sum - min_sum + 1) * n)
