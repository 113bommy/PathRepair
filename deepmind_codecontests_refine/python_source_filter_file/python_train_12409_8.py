a, b = map(int, input().split())
c = set()
d = 0
for i in range(a + 1, b + 1):
  c.clear()
  for t in str(i):
    c.add(t)
  if len(c) == len(str(i)):
    d = i
    break
  elif len(c) < len(str(i)) and i == b:
    d = -1
    break
print(d)