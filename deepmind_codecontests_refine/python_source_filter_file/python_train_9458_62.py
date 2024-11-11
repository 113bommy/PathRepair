import re

S = input()
print("Yes" if re.match("^(dream|dreamer|erase|eraser)+$", S) else "No")