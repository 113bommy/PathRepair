n, *a = map(int, open(0).read().split())
MOD = 10**9 + 7
c = 0
for i in range(61):
  i = 2**i
  t = sum(i & b and 1 for b in a)
  c = (c + t * (n - t) * i) % MOD
print(c)