R = lambda: map(int, input().split())
R()
a = [0] * 100001
s = 0
for x in R():
  s += x
  a[x] += 1
q, = R()
for _ in range(q):
  b, c = R()
  s += (c - b) * a[b]
  print(s)
  a[c]+=a[b]
  a[b] = 0
