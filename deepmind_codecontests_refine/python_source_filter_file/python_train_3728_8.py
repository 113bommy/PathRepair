x, y, z, k = list(map(int, input().split()))
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))

d = []

for e1 in a:
  for e2 in b:
    d.append(e1+e2)

d.sort(reverse=True)
d = d[:k]

e = []

for e1 in d:
  for e2 in c:
    e.append(e1+e2)

e.sort(reverse=True)

for i in range(k):
  print(e[i])