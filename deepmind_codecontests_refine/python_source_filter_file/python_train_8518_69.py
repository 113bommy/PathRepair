import re
s = input()
if re.match(r'[A]?KIH[A]?B[A]?R[A]?', s):
    print('YES')
else:
    print('NO')
