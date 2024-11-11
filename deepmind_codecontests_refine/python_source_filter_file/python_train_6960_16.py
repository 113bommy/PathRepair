xmax,ymax,N=map(int,input().split())
xmin=0
ymin=0

for i in range(N):
    x,y,a=map(int,input().split())
    if a==1:
        xmin=max(xmin,x)
    elif a==2:
        xmax=min(xmax,x)
    elif a==3:
        ymin=max(ymin,y)
    else:
        ymax=min(ymax,y)
print(max(0,(xmax-xmin)*(ymax-ymin)))