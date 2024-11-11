import re

s = input()
if re.fullmatch(r'A?KIHA?BA?RA?', s) == None:
    print('NO')
else:
    print('YES')


