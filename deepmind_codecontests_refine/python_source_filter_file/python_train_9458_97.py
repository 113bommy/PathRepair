import re
S = input()
print("YES" if re.match("(dream|dreamer|erase|erase)+", S) else "NO")