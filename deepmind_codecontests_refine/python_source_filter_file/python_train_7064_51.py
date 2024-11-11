import re
S1 = input()
p = r'C*F'
result = re.match(p, S1)
if result:
    print('yes')
else:
    print('No')
