n, *a = map(int, open(0).read().split())
m = 0
for i in range(n+1):
  m = max(m, sum(a[:i] + a[n+i:]))
print(m)