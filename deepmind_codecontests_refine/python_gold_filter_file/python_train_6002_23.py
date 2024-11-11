n, m = [int(x) for x in input().split(' ')]
a = list(range(1, n + 1))
cnt = 0
while m - a[cnt] >= 0:
  m -= a[cnt]
  cnt += 1
  if cnt == n: cnt = 0
print(m)
