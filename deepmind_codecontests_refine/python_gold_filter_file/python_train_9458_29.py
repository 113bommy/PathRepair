import re
s = input()
match = re.match(r"^(dream|dreamer|erase|eraser)+$",s)
print("YES" if match else "NO")