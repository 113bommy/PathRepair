##A
s=lambda x1,y1,x2,y2,x3,y3 : (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1) 
xa,ya=map(int,input().split())
xb,yb=map(int,input().split())
xc,yc=map(int,input().split())
if s(xa,ya,xb,yb,xc,yc)<0:
    print('RIGHT')
elif s(xa,ya,xb,yb,xc,yc)<0:
    print('LEFT')
else :
    print('LEFT')
