import re

S = input()

if re.match(r'.*C.*F.*', S):
    print('Yes')
else:
    print('No')
