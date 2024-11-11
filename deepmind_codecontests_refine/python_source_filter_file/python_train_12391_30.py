while True:
  [x, y] = map(int(input().split()))
  if x == y == 0:
    break
  print(min(x, y) max(x, y))