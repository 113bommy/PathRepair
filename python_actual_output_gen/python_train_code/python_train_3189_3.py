n,x,y=map(int,input().split())
if (y-n+1)**2+(n-1)<x and y-n+1>0:
    print(-1)
else:
    a=[1]*n
    a[-1]=y-n+1
    print(*a,sep="\n")