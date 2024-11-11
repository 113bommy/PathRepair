import re

s = input()
if re.fullmatch(r'A?KIA?HA?BA?RA?', s) == None:
    print('NO')
else:
    print('YES')


