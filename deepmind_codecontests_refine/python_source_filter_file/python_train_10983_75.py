import re
s = str(input())
c=0
c1=0

for i in s:
        if(re.search("[A-Z]",s)):
                c+=1
        if(re.search("[a-z]",s)):
                c1+=1
if(c>c1):
        s = s.upper()
else:
        s = s.lower()
print(s)
