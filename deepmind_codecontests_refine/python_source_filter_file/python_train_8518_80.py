import re
r = re.fullmatch(r'[A]?KIH[A]?B[A]?R[A]?', input())
if r:
    print ("Yes")
else:
    print ("No")
