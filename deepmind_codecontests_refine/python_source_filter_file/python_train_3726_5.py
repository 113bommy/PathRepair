n=int(input())
xy=[list(map(int,input().split())) for _ in range(n)]
sgm=pow(10.-7)
def func(c):
    allp=[]
    for i in range(n-1):
        for j in range(i+1,n):
            xi,yi=xy[i]
            xj,yj=xy[j]
            dx=xi-xj
            dy=yi-yj
            d=((xi-xj)**2+(yi-yj)**2)**0.5
            if c**2-(d/2)**2<0:return False
            h=(c**2-(d/2)**2)**0.5
            mx,my=(xi+xj)/2,(yi+yj)/2
            if dx==0:
                allp.append([mx-h,my])
                allp.append([mx+h,my])
            elif dy==0:
                allp.append([mx,my-h])
                allp.append([mx,my+h])
            else:
                dx,dy=dy,-dx
                dh=(dy**2+dx**2)**0.5
                dx*=h/dh
                dy*=h/dh
                allp.append([mx+dx,my+dy])
                allp.append([mx-dx,my-dy])
    for px,py in allp:
        flg=True
        for x,y in xy:
            if ((px-x)**2+(py-y)**2)**0.5>c+sgm:
                flg=False
                break
        if flg:
            return True
    return False

r=2*max([abs(x) for x,y in xy])+max([abs(y) for x,y in xy])
l,r=0,r
for i in range(300):
    c=(l+r)/2
    if func(c):
        l,r=l,c
    else:
        l,r=c,r
print(c)
#print(c**2)