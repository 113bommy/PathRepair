n, k = map(int, input().split())
minm = min(1, n - k)
if k >= n // 2:
    maxm = n - k
else:
    maxm = min(n - k, 2 * k)
print(minm,maxm)