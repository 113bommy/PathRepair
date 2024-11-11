import os,io
input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
import bisect
mod = 998244353

def fpow(a, b):
    ans = 1
    while b:
        if (b & 1): ans = (ans * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    return ans

n, m = map(int, input().split())

d = list(map(int, input().split()))
d = sorted(d)

pre = [0 for _ in range(n + 1)]
for i in range(n):
    pre[i + 1] = pre[i] + d[i]

for _ in range(m):
    a, b = map(int, input().split())
    k = bisect.bisect_left(d, b) # 二分查找
    low = max(0, n - k - a)
    upp = max(0, n - k - a + 1)

    # 1 - (a / k)
    print(low * fpow(n - k, mod - 2) * (pre[n] - pre[k] + mod) % mod + upp * fpow(n - k + 1, mod - 2) * pre[k] % mod)



