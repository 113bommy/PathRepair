import re

S = str(input())

print("Yes" if re.match("^(dream|dreamer|erase|eraser)+$", S) else "No")