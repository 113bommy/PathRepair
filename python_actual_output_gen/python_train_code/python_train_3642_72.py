r, d, x = map(int, input().split())

for i in range(11):
  x = r * x - d
  print(x)