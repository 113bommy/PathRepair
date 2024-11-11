import re
S = input()
if re.match(r"^(dream|dreamer|erase|eraser)*$", S):
    print("YES")
else:
    print("NO")