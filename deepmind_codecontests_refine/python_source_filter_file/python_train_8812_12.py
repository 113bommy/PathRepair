n, k, m, d = map(int, input().split())

ans = 0

for y in range(1, d + 1):
  x = min(m, n // (k * (y - 1) + 1))
  if x == 0:
    continue
  yy = (n // x + k - 1) / k
  if yy != y:
    continue
  ans = max(ans, x * y)
print(ans)