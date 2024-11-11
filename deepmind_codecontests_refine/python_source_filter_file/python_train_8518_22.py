import re
s = input()
if re.match(r'A?KIHA?BA?RA?', s):
    print('YES')
else:
    print('NO')
