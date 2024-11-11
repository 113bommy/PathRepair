M = 10**9 + 7
n, a, b = map(int, input().split())
r = pow(2, n, M) - 1
f = c = 1
for i in range(b):
  f = f * (i + 1) % M
  c = c * (n - i) % M
  if i + 1 == a:
    r -= c * pow(f, M - 2, M)
print((r - c * pow(f, M - 2, M) % M))