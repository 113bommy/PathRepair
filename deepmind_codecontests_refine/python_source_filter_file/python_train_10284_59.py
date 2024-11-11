k = int(input())
a, b = map(int, input().split())
c = (b//k) * k
if c >= a:
  print('OK')
else:
  print('NO')