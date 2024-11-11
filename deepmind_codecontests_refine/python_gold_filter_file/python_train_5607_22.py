x,y=map(int,input().split())

ans=abs(abs(x)-abs(y))

if y<x<0 or 0<y<x:
    ans+=2

elif y<x or x<0<y:
    ans+=1

print(ans)