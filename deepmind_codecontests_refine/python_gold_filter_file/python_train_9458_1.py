import re
S = str(input())
print("YES" if re.match("^(dream|dreamer|erase|eraser)+$", S) else "NO")