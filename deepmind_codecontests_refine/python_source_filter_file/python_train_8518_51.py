import re
s = input()
m = re.compile('(A){0,1}KIH(A){0,1}B(A){0,1}R(A){0,1}')
if m.match(s):
  print('YES')
else:
  print('NO')