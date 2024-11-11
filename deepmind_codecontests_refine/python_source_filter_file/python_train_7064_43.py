import re
S = input()
print('NO' if re.search(r'C.*F', S) is None else 'YES')