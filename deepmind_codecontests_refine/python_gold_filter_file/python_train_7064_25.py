import re
s = input()
if re.search('C.*F', s):
    print('Yes')
else:
    print('No')