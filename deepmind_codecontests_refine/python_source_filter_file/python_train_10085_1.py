import re
print(*[x for x in re.split(r'\s|"|,|\.',input())if 2<len(s)<7])
