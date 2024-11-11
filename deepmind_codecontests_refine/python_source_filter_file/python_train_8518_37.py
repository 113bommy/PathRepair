import re

S = input()
print('Yes' if re.match(r'A?KIHA?BA?RA?', S) else 'No')
