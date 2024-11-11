n, k = map(int, input().split())
c1 = 1
c2 = 1
mod = 10**9+7
ans = 0

for i in range(min(n, k+1)):
  ans += c1 * c2
  c1 *= (n-i) * pow(i+1, mod-2, mod)
  c1 %= mod
  c2 *= (n-i-1) * pow(i+1, mod-2, mod)
  c2 %= mod

print(ans)