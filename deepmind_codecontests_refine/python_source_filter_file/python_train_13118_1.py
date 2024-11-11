import sys
d=[]
input()
for e in sys.stdin:
 c,g=e.split()
 if'i'==c[0]:d+=[g]
 else:print(['no','yes'][g in d])
