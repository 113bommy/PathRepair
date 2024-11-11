a,b,c = input().split()

if a[-1:] == b[:1] and b[-1:] == c[:1]:
  print('YES')
else:
  print('NO')