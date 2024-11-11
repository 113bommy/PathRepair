 x, y = map(int, input().split())
if y%2 == 0 and (x*2 <= y <= x*4):
  print('Yes')
else:
  print('No')