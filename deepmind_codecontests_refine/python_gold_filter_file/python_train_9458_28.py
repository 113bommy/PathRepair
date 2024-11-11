import re
d = input()
if re.match("(dream|dreamer|erase|eraser)+$",d):
  print('YES')
else:
  print('NO')