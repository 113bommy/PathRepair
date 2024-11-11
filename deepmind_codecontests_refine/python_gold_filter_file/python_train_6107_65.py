import re

s = input()
print(['NO', 'YES'][len(re.findall('(0{7}|1{7})', s)) > 0])