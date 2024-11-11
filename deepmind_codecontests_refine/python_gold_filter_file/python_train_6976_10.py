n = int(input())
l = []
for i in input().split():
  t = []
  for j in i: t += [j]
  l += [t]

t = l[:]
f = 0
for i in range(n):
  for j in range(n-1, 0, -1):
    if t[j][1] < t[j-1][1]:
      t[j], t[j-1] = t[j-1], t[j]
    elif t[j][1] == t[j-1][1]:
      f += 1 if l.index(t[j-1]) > l.index(t[j]) else 0
print(*["{0}{1}".format(i[0], i[1]) for i in t])
print("Not stable" if f > 0 else "Stable")

x = l[:]
f = 0
for i in range(n):
  m = i
  for j in range(i, n):
    if x[j][1] < x[m][1]:
      m = j
    elif x[j][1] == x[m][1]:
      f += 1 if l.index(x[m]) > l.index(x[j]) else 0
  x[i], x[m] = x[m], x[i]
print(*["{0}{1}".format(i[0], i[1]) for i in x])
print("Not stable" if f > 0 else "Stable")
