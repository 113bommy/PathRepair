n, *A = map(int, open(0).read().split())
mod = 10**9 + 7
ans = 0
d = 1
while any(A):
  c = 0
  for i in range(n):
    q, r = divmod(A[i], 2)
    A[i] = q
    c += r
  ans += c*(n-c) * d
  ans %= mod
  d *= 2
print(ans % mod)