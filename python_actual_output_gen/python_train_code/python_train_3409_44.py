n, k = map(int, input().split())
print(max(0, min(n, (k - 1) // 2) - (k - n) + 1))
