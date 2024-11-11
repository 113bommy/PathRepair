x, y = map(int, input().split())
d = abs(abs(x) - abs(y))
if 0 <= x < y or x < y <= 0:
  print(d)
elif y <= 0 <= x or x < 0 < y:
  print(d+1)
else
  print(d+2)