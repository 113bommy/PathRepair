x, y = map(int, input().split())
if (0 < x < y) or (x < y < 0):
  print(y - x)
elif (0 < y < x) or (y < x < 0):
  ans = 2 + abs(x - y)
  print(ans)
else:
  ans = 1 + abs(abs(x) - abs(y))
  print(ans)