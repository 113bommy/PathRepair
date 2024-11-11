import re

S = input()
matchObj = re.match("^A[a-z]C[^C]*[a-z]$", S)
if matchObj:
  print("AC")
else:
  print("WA")