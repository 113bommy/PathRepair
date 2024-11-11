def gc(a,b):
    if a==0:
        return 0,1
    else:
        x,y=gc(b%a,a)
    return y-(b//a)*x,x 

import math
a,b,c=map(int,input().split())
x=-5*(10**18)
if b==0:
    if c%a==0:
        print(-c//a,0)
    else:
        print("-1")
    exit()
elif a==0:
    if c%b==0:
        print(0,-c//b)
    else:
        print("-1")
    exit()
d=math.gcd(a,b)
if c%d!=0:
    print("-1")
    exit()
c=-c
sx=a//abs(a)
sy=b//abs(b)
if abs(a)>abs(b):
    x,y=gc(abs(b),abs(a))
    print(sx*y*c//d,sy*x*c//d)
else:
    x,y=gc(abs(a),abs(b))
    print(sx*x*c//d,sy*y*c//d)