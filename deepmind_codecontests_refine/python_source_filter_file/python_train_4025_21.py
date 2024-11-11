hh,mm=list(map(int, input().split()))
t=hh*60+mm
h,d,c,n=list(map(int, input().split()))

import math
if t>=20*60:
    print(0.8*c*(h/n))
else:
    res=c*math.ceil(h/n)
    h+=(1200-t)*d
    res=min(res, 0.8*c*math.ceil(h/n))
    #print(c*math.ceil(h/n), 0.8*c*math.ceil(h+((1200-t)*d))/n))
    print(res)
