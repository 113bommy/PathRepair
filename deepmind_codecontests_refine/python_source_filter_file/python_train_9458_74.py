import re

regex = r'(dream|dreamer|erase|eraser)+$'

s = raw_input()

if re.match(regex, s):
  print("YES")
else:
  print("NO")