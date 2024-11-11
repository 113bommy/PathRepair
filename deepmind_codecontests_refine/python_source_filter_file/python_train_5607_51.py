x,y=map(int,input().split())
ans=abs(abs(x)-abs(y))
if x*y<0:
  ans+=1
elif 0<y<x or y<x<0:
  ans+=2
elif x*y==0 and x<y:
  ans+=1
print(ans)