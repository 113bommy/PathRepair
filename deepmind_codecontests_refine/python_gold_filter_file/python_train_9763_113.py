a, b, c, k = list(map(int, input().split()))
print(min(a, k) - max((k - (a + b), 0)))
