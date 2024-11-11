from math import sqrt
n, m = map(int, input().split())
t = min(int(sqrt(n))+1, m)
i = 2
mod = 10**9 + 7
ans = 0

while i <= t:
    ans += n % i
    i += 1

ans %= mod
i = t + 1

while i <= min(n, m):
    d = n // i
    t = min(m, n // d)
    cnt = t - i + 1
    x = (n % i) * cnt - d * (((cnt-1) * cnt) >> 1)
    ans = (ans + x) % mod
    i = t + 1

if i < m:
    ans = (ans + n * (m-i+1)) % mod

print(ans)
