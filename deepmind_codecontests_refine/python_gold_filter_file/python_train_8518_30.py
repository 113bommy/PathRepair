import re
s = input()
if re.fullmatch("A?KIHA?BA?RA?",s):
    print("YES")
else:
    print("NO")