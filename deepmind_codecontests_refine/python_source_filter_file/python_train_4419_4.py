n = int(input())
x = []
for i in range(n):
  c, p = map(int, input().split())
  x += [(p, c, i)]
k = int(input())
r = list(map(int, input().split()))
s = 0
q = []
for (v, c, a) in reversed(sorted(x)):
  p = -1
  u = 100000
  for  (j, z) in enumerate(r):
    if c < z < u:
      p = j
      u = z
  if p > -1:
    r[p] = 0
    q += [(a, p)]
    s += v
print(len(q), s)
for (i, j) in q:
  print(i + 1, j + 1)