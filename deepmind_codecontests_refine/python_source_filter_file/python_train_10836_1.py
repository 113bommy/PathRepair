n = int(input())
ans = 0
mod = 998244353
a = list(map(int, input().split()))
p = 1 / 2

for i in range(n):
    ans = (ans + (i + 2) * p * a[n - i - 1] % mod) % mod
    p = (2 * p) % mod

print(int(ans) % mod)