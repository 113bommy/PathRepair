x0,y0,ax,ay,bx,by=map(int,input().split())
xs,ys,t=map(int,input().split())
d0=d2=abs(x0-xs)+abs(y0-ys)
ans=0
tmp=0
while d0>t:
    x0,y0=x0*ax+bx,y0*ay+by
    tmp=abs(x0-xs)+abs(y0-ys)
    if tmp>d0:break
    d0=d2=tmp
while tmp<t:
    x, y = x0, y0
    if tmp>0:d0=d2=tmp
    d1=0
    r=0
    while d0+d1<=t or d2+d1<=t:
        x,y=x*ax+bx,y*ay+by
        d1=x-x0+y-y0
        d2=abs(x-xs)+abs(y-ys)
        r+=1
    ans=max(ans,r)
    x0, y0 = x0 * ax + bx, y0 * ay + by
    tmp=abs(x0-xs)+abs(y0-ys)
print(ans)