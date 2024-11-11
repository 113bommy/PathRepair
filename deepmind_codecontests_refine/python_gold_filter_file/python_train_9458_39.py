import re

regex = r'(dream|dreamer|erase|eraser)+$'

s = input()

if re.match(regex, s):
  print("YES")
else:
  print("NO")