import re
s=input()
if re.match(r"(dream|dreamer|erase|eraser)+$",s):
    print("YES")
else:
    print("NO")