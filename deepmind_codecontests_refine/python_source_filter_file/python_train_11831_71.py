import re

s = input().lower()

s = re.sub("[^aeuioy]", '', s)
print(len(s))