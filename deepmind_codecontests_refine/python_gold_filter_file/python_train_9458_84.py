import re

s = input()
print('YES' if re.match('^(dream|dreamer|erase|eraser)+$', s) else 'NO')