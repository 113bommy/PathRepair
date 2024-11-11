a = int(input())
b = list(input() for i in range(a))
c = int(input())
d = list(input() for i in range(c))
e = list()

for s in b:
  e.append(b.count(s)-d.count(s))
else:
  print(max(e))