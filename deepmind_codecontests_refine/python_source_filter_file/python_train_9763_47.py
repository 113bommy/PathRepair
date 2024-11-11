a, b, c, k = map(int, input().split())
print(min(a, k) - min(c, k - (a + b)))
