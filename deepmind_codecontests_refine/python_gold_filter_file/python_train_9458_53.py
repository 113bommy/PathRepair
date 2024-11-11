import re
s = input()

if re.match("(dreamer|dream|eraser|erase)+$",s):
  print("YES")
else:
  print("NO")