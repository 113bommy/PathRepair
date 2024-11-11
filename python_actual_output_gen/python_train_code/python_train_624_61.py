a, b, c, k = (int(i) for i in input().split())
if 0 == (k & 1):
  print(b - a)
else:
  print(a - b)
  