import re
s=input()
if re.search(r"^(dreamer|dream|erase|eraser)*$",s):
    print("YES")
else:
    print("NO")