x1,y1,x2,y2=map(int,input().split())
l=abs(x2-x1);m=abs(y2-y1)
if l==0:
    print(x1+m,y1,x2+m,y2)
elif m==0:
    print(x1,y1+m,x2,y2+m)
elif l!=m:
    print(-1)
else:
    print(x2,y1,x1,y2)