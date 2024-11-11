inputlist=list(map(int, input().split()))
import math
r=inputlist[0]
b=inputlist[1]
g=inputlist[2]
a=max(r,b,g)
c=min(r,b,g)
b=r+b+g-(a+b)
if a>=2*(b+c):
    print(b+c)
else:
    print(math.floor((a+b+c)/3))
