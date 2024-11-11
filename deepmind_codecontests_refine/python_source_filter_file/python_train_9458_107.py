import re
S = input()
if re.match("^(dreamer|dream|erase|eraser)+$", S):
    print("Yes")
else:
    print("No")