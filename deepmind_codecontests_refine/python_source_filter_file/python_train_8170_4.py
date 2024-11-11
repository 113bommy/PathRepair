from decimal import *
import math
getcontext().prec=50


a,b=map(Decimal, input().split())
if b>a:
    print (-1)
else:
    cur=-1
    if (a+b)%2==0:
        cur=(a+b)//2
    else:
        cur=(a+b)/Decimal(2)
    print(cur/math.floor(cur))

