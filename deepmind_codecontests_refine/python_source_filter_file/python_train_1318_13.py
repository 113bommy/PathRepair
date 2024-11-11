s = input()
a = s.count('-')
a = min(len(s)-a, a)
c = len(s)

if a == 0 or c % a == 0:
  print('YES')
else:
  print('NO')
