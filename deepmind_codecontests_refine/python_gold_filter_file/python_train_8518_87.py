import re
p="^A?KIHA?BA?RA?$"
s=input()
if re.match(p,s):print("YES")
else:print("NO")