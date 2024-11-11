n, k = map(int, input().split())

res = (min(n, k - 1) - max(0, k - n - 1)) // 2
print(res)
