w,h,n=map(int,input().split())
xa=0
xb=w
ya=0
yb=h
for i in range(n):
    x,y,a=map(int,input().split())
    if a==1:
        xa=max(x,xa)
    if a==2:
        xb=min(x,xb)
    if a==3:
        ya=max(y,ya)
    if a==4:
        yb=min(y,yb)
print(max((xb-xa)*(yb-ya),0))