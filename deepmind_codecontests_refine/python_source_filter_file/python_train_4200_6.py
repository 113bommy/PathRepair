n, m, x, y = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

i = j = 0
c = []
d = []

while i < n and j < m:
  if b[j] >= a[i] - x and b[j] <= a[i] + y:
    c.append(i + 1)
    d.append(j + 1)
    i += 1
    j += 1
  elif a[i] + y < b[j]:
    j += 1
  else:
    i += 1

print(len(c))
for i in range (len(c)):
  print(c[i], d[i])