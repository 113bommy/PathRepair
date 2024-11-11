import re
S = input()
print('No' if re.search(r'C.*F', S) is None else 'Yes')
