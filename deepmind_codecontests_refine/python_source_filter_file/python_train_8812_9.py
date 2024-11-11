n, k, M, D = map(int, input().split())
res = 0
for d in range(1, D + 1):
    x = n / (d * k - k + 1)
    x = min(x, M)
    res = max(res, x * d)
print(res)