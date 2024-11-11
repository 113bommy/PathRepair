x,y=map(int,input().split())

dist=abs(abs(x)-abs(y))
if x<=y:
  if x*y>=0:
    ans=dist
  else:
    ans=dist+1
else:
  if x*y>=0:
    ans=dist+2
  else:
    ans=dist+1

print(ans)