import re
S = input()
print("YES" if re.match(r'^(dream|dreamer|erase|eraser)*$', S) else "NO")