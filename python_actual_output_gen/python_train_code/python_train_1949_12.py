x,y = map(int,input().split())
ans = 10**10
if x<=y: ans = min(ans,y-x)
if -x<=y: ans = min(ans,1+y-(-x))
if x<=-y: ans = min(ans,-y-x+1)
if -x<=-y: ans = min(ans,-y-(-x)+1)
print(ans)
