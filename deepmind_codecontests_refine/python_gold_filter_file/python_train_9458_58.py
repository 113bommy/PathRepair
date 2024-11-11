import re;
s = input();
print("YES" if re.fullmatch(r'^(dream|dreamer|eraser|erase)*$', s) else "NO")
