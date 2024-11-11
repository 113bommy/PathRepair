import sys
from math import *
from fractions import gcd
readints=lambda:map(int, input().strip('\n').split())


n,x1,x2=readints()
t1,t2=readints()
p,d=readints()

if x1==x2:
    print(0)
    sys.exit(0)

walking=abs(x2-x1)*t2

trainx1=0
d2 = (x2-x1)//abs(x2-x1)

# same dir
if d==d2:
    if d==1:
        if p<=x1:
            trainx1=abs(x1-p)*t1
        else:
            trainx1=(abs(n-p)+n+abs(x1-0))*t1
    else:
        if p>=x1:
            trainx1=abs(x1-p)*t1
        else:
            trainx1=(abs(p-0)+n+abs(x1-n))*t1
else:
    if d==1:
        trainx1=(abs(n-p)+abs(n-x1))*t1
    else:
        trainx1=(abs(p-0)+abs(x1))*t1
    

trainx2=abs(x2-x1)*t1
# print(trainx1,trainx2)


print(min(walking,trainx1+trainx2))
