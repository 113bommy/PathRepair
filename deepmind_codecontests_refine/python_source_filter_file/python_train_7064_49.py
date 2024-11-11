import re

s = input()

if re.match(r'C.*F', s):
    print('Yes')
else:
    print('No')

