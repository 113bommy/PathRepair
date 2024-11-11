import math
for _ in range(int(input())):
    r,b,k=map(int,input().split())
    xx=min(r,b)
    yy=max(r,b)
    if(yy%xx==0):
        req=yy//xx-1
    else:
        req=yy/xx
    z=math.gcd(xx,yy)
    zz=xx//z-1
    if(zz>((req+1)*xx-yy)//z):
        req+=1
    if(req>=k):
        print('REBEL')
    else:
        print('OBEY')