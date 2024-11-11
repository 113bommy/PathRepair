import re

a = input()
b = input()
c = input()
if(len(re.findall('[aouei]', a)) == 5 and len(re.findall('[aouei]', b)) == 7 and len(re.findall('[aouei]', c)) == 5):
    print("YES")
else:
    print("NO")
