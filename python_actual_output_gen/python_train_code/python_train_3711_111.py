a, b, c, d = map(int, input().split())
if abs(c-a) <= d or (abs(c-b) <= d and dabs(b-a) <= d):
  print('Yes')
else:
  print('No')
