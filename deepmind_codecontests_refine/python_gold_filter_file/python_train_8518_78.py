import re
r = re.fullmatch(r'[A]?KIH[A]?B[A]?R[A]?', input())
if r:
    print ("YES")
else:
    print ("NO")
