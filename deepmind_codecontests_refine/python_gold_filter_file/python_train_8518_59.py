import re

S = input()

if re.fullmatch("A?KIHA?BA?RA?", S):
    print("YES")
else:
    print("NO")