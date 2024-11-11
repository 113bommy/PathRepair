x, r, D = map(int, input().split())
for _ in range(1, 11):
  x = r*x - D
  print(x)