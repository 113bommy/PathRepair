n,k = map(int, input().split())
res = -100000000
for _ in range(n):
    n,m = map(int, input().split())
    if m > k:
        n -= (m-k)
    res = max(res, n)
print(res)
