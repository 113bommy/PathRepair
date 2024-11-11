import re
s = input()
if re.match(r'(hi)+', s):
  print('Yes')
else:
  print('No')