import re
S=input()
if re.fullmatch(r'hi+',S):
    print("Yes")
else:
    print("No")
