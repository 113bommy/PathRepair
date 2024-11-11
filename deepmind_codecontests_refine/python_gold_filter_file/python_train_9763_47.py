a, b, c, k = map(int, input().split())
print(min(k, a) - max(0, k - (a + b)))