import re

s = input()

m = re.match(r"^(dream|dreamer|erase|eraser)+$", s)

print("No" if m is None else "Yes")