a = input()
line = 'CODEFORCES'
line_stat = 'CODEFORCES'
i = 0
t = False
if len(a) > 10:
 if a[0:10:] == 'CODEFORCES':
  t = True
 elif a[(len(a) - 11):(len(a) - 1):] == 'CODEFORCES':
  t = True
 else:
  while a[i] == line[0]:
    line = line[1::]
    i += 1
  m = len(line)
  if a[(len(a) - m):len(a):] == line:
   t = True
if t == True:
 print('YES')
else:
 print('NO')
