import re
sin = input()
match = re.match(r"^.*(dream|dreamer|erase|eraser)+$",sin)
print("YES" if match else "NO")