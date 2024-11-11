n, m = map(int, input().split())
f = sorted(map(int, input().split()))
res = max(f) - min(f)
for i in range(m - n):
  res = min(res, f[i + n - 1] - f[i])
print(res)