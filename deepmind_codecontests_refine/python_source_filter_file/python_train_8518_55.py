import re

s = input()
regex = re.compile(r"A?KIHA?BA?RA?")
if regex.match(s):
    print("Yes")
else:
    print("No")