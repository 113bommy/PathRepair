import os
from io import BytesIO
input = BytesIO(os.read(0, os.fstat(0).st_size)).readline

n, k = map(int, input().split())
a = [int(input()) for i in range(n)]
dp = [[0] * (n + 1) for i in range(k + 1)]

def query(f, i):
    r = 0
    while i > 0:
        r += f[i]
        i -= i & -i
    return r

def update(f, i, r):
    while i <= n:
        f[i] += r
        i += i & -i

res = [1] * n
for i in range(n):
    update(dp[0], a[i], 1)
    for j in range(1, k + 1):
        res[i] = query(dp[j - 1], a[i] - 1)
        update(dp[j], a[i], res[i])

print(sum(res))