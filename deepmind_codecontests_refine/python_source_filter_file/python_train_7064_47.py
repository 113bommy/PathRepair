import re
print('Yes') if len(re.compile(r'.+C.+F.+').findall(input()))>=1 else print('No')