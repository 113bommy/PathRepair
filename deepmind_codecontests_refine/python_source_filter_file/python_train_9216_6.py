n, a, b, c, d = map(int, input().split())
print((n - (max(a+b, b+d, a+c, c+d) - min(a+b, b+d, a+c, c+d))) * n)