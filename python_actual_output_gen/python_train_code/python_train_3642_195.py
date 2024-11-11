r, d, x = map(int, input().strip())
for i in range(10):
  x = r * x - d
  print(x)
