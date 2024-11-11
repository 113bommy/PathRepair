import re
s = input()
if re.match("^A{0,1}KIHA{0,1}BA{0,1}RA{0,1}$", s):
  print("YES")
else:
  print("NO")