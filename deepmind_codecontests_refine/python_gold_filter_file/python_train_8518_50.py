import re

s = input()
regex = re.compile(r"A?KIHA?BA?RA?")
if regex.fullmatch(s):
    print("YES")
else:
    print("NO")