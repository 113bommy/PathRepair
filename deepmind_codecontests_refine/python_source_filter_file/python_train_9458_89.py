import re;
s = input();
print("Yes" if re.fullmatch(r'^(dream|dreamer|eraser|erase)*$', s) else "NO")
