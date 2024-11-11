mod = 10**9 + 7

r1, c1, r2, c2 = map(int, input().split())

fact = [1] * (r2 + c2 + 3)
inv = [1] * (r2 + c2 + 3)
inv_fact = [1] * (r2 + c2 + 3)
for i in range(2, r2 + c2 + 3):
  fact[i] = fact[i-1] * i % mod
  inv[i] = -inv[mod % i] * (mod // i) % mod
  inv_fact[i] = inv_fact[i-1] * inv[i] % mod

total = fact[r2 + c2 + 2] * inv_fact[r2 + 1] * inv_fact[c2 + 1] % mod
total -= fact[r1 + c2 + 1] * inv_fact[r1] * inv_fact[c2 + 1] % mod
total -= fact[r2 + c1 + 1] * inv_fact[c1] * inv_fact[r2 + 1] % mod
total += fact[r1 + c1] * inv_fact[r1] * inv_fact[c1] % mod

print(total)