W,H,N=map(int,input().split())
xl,xr,yh,yl=0,W,H,0
for i in range(N):
    x,y,a=map(int,input().split())
    if a==1:
        xl=max(xl,x)
    elif a==2:
        xr=min(xr,x)
    elif a==3:
        yl=max(yl,y)
    elif a==4:
        yh=min(yh,y)
print(max(xr-xl,0)*max(yh-yl,0))