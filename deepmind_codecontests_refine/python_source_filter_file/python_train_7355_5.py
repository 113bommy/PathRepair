n,x,y=map(int,input().split())
import math
s=x+y;x=max(x,y);y=s-x
a=list(map(str,input().split('*')))
b=[]
for i in a:
    if "." in i :
        b.append(len(i))
ans=0
for i in b:
    n=math.ceil(i/2)
    m=math.floor(i/2)
    l=min(n,x);ans+=l
    x-=(l)
    l=min(m,y);ans+=l
    y-=m
    s=x+y;x=max(x,y);y=s-x
    #print(x,y,l)
print(ans)

    