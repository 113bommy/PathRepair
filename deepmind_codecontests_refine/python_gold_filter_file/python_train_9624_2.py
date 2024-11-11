n, m, k = map(int, input().split())
if k > n + m - 2:
    print(-1)
    exit()
res = 0
if k < n:
    res = max(res, n // (k + 1) * m)
else:
    res = max(res, m // (k - (n - 1) + 1))
if k < m:
    res = max(res, m // (k + 1) * n)
else:
    res = max(res, n // (k - (m - 1) + 1))
print(res)
