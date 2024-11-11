a, b, c, k = list(map(int, input().split()))
print(a - max((k - (a + b), 0)))
