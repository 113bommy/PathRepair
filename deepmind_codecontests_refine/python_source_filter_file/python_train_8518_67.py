import re

s = input()
if re.fullmatch(r'.?KI.?H.?B.?R.?', s) == None:
    print('NO')
else:
    print('YES')


