import re;
s = input();
print("Yes" if re.match(r'^(dream|dreamer|eraser|erase)*$', s) else "NO")
