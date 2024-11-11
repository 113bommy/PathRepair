import re
S1 = input()
p = r'C*F'
result = re.search(p, S1)
if result:
    print('Yes')
else:
    print('No')