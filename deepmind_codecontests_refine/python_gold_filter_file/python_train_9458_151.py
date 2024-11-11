import re

s = input()

m = re.match(r"^(dream|dreamer|erase|eraser)+$", s)

print("NO" if m is None else "YES")