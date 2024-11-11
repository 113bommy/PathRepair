import re
s = input()
if re.search(r'[A]?KIH[A]?B[A]?R[A]?', s):
    print('YES')
else:
    print('NO')
