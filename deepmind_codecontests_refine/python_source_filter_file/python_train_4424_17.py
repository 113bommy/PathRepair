s = input()
t = 'CODEFORCES'
k = 0
for i in range(len(t)):
   if s.startswith(t[:i]) and s.endswith(t[i:]):
       print('YES')
       break
else:
    print('NO')