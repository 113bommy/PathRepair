x,y = map(int,input().split())
ans = float("inf")
if y>=x:
  ans = min(ans,y-x)
if -y>=x:
  ans = min(ans,-y-x+1)
if -y>=-x:
  ans = min(ans,-y-x+2)
if y>=-x:
  ans = min(ans,y+x+1)
print(ans)