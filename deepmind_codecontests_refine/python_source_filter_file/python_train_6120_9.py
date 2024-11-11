import sys
input = sys.stdin.readline
from math import sqrt

N,K=map(int,input().split())
M=[tuple(map(int,input().split())) for i in range(N)]

def cross_coor(x0,y0,c0,x1,y1,c1): # 二円の交点
    if (c1-c0)**2<=(x1-x0)**2+(y1-y0)**2<=(c0+c1)**2:
        x2,y2=x1-x0,y1-y0
        a=(x2**2+y2**2+c0**2-c1**2)/2

        xa=(a*x2+y2*sqrt((x2**2+y2**2)*(c0**2)-a**2))/(x2**2+y2**2)+x0
        ya=(a*y2-x2*sqrt((x2**2+y2**2)*(c0**2)-a**2))/(x2**2+y2**2)+y0

        xb=(a*x2-y2*sqrt((x2**2+y2**2)*(c0**2)-a**2))/(x2**2+y2**2)+x0
        yb=(a*y2+x2*sqrt((x2**2+y2**2)*(c0**2)-a**2))/(x2**2+y2**2)+y0

        return [(xa,ya),(xb,yb)]
    else:
        return False

OK=1<<18
NG=0

while OK-NG>10**(-8):
    mid=(OK+NG)/2
    
    CANDI=[]
    for i in range(N):
        x0,y0,c0=M[i]
        CANDI.append((x0,y0))
        for j in range(i+1,N):
            x1,y1,c1=M[j]
            CR=cross_coor(x0,y0,mid/c0,x1,y1,mid/c1)
            if CR:
                CANDI.extend(CR)

    for z,w in CANDI:
        count=0
        for x,y,c in M:
            if (c**2)*((x-z)**2+(y-w)**2)<=(mid+10**(-8))**2:
                count+=1
            
        if count>=K:
            OK=mid
            break
    else:
        NG=mid

print((OK+NG)/2)

