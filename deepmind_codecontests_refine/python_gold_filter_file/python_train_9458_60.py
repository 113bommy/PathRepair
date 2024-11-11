import re
s = input()
if re.match("(dream|dreamer|erase|eraser)+$", s):
    print("YES")
else:
    print("NO")