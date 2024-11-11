import re

s = input()
print('Yes' if re.match('^(dream|dreamer|erase|eraser)+$', s) else 'No')