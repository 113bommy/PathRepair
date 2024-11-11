a, b = map(int, input().split())
c, d = map(int, input().split())
if d >= a / 2 and a >= (d - 1) / 2:
  print('YES')
elif c >= b / 2 and b >= (c - 1) / 2:
  print('YES')
else:
  print('NO')