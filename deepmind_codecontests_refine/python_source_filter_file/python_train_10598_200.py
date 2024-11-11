r, D, x = map(int, input().split())
for i in range(10):
  r = r * x - D
  print(r)