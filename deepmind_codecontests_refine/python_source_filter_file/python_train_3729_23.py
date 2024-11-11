from bisect import bisect_left
n, m = map(int, input().split())
data = [list(map(int, input().split())) for _ in range(n)]
t = [[] for _ in range(n)]
for p, y in data:
  t[p - 1].append(y)
for i in range(n):
  t[i].sort()
for p, y in data:
  nth = bisect_left(t[p - 1], y) + 1
  print("%06d%06d" % (p, nth))
