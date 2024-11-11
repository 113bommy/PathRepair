k = int(input())
a, b = map(int, input().split())
if (b-a) >= k:
  print('OK')
else:
  print('NG')