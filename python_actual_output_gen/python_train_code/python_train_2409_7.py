o1=0
o2=0
oo1=0
oo2=0
w,h,n=map(int,input().split())
for i in range(n):
    x,y,a=map(int,input().split())
    if a==1:
        oo1=max(o1+x,oo1)
    elif a==2:
        w=min(x,w)
    elif a==3:
        oo2=max(o2+y,oo2)
    else:h=min(y,h)
if o1>=w or o2>=h:
    print(0)
else:print((w-oo1)*(h-oo2))