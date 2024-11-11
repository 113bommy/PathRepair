import sys
input = sys.stdin.readline

n, k = map(int, input().split())
mod = 998244353
s = list(input().rstrip())
l = n + 5
fact = [1] * (l + 1)
for i in range(1, l + 1):
    fact[i] = i * fact[i - 1] % mod
inv = [1] * (l + 1)
inv[l] = pow(fact[l], mod - 2, mod)
for i in range(l - 1, -1, -1):
    inv[i] = (i + 1) * inv[i + 1] % mod

def comb(n, r):
    return fact[n] * inv[r] % mod * inv[n - r] % mod if n >= r >= 0 else 0

x = [-1]
for i in range(n):
    if s[i] == "1":
        x.append(i)
x.append(n)
l = len(x) - 1
ans = 1
for i in range(1, len(x) - 1):
    xi = x[i]
    l = i - 1 if i < k else x[i - k] + 1
    for j in range(l, x[i + 1]):
        if xi == j:
            continue
        c = min(i - 1, k - 1)
        m = j - 1 - x[max(0, i - k)]
        ans += comb(m, c)
        ans %= mod
if len(x) - 2 < k:
    ans = 0
print(ans)