import re

s = input()
t = re.sub('0{7,}|1{7,}', '', s)

print('YES' if s != t else 'NO')
