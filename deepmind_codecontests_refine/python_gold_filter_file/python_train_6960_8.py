l,d=0,0
w,h,n=map(int,input().split())
for _ in [0]*n:
    x,y,a=map(int,input().split())
    if a==1 and l<x:l=x
    elif a==2 and w>x:w=x
    elif a==3 and d<y:d=y
    elif a==4 and h>y:h=y
if w<=l or h<=d:print(0)
else:print((w-l)*(h-d))