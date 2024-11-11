import re

s = input().strip()

s = re.sub('(\d)\s+(?=\d)', r'\1x', s)
s = re.sub('\s', '', s)
s = re.sub(',', ', ', s)
s = re.sub('\.\.\.', ' ...', s)
s = re.sub('^\s|\s$', '', s)
s = re.sub('\s\s', ' ', s)
s = re.sub('x', ' ', s)

print(s)

