import sys
lc=lambda n:int((n**2+n+2)/2)
[print(i) for i in [lc(int(j)) for j in sts.stdin]]
