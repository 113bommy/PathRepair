n, k = map(int, input().split())
print(k * (k - 1) ** max(0, n - 1))
