a,b,c,x,y=map(int,input().split())

m=max(x,y)
ans=10**9+7
for e in range(m+1):
  ans=min(ans,2*e*c+a*max(0,x-e)+b*(0,y-e))
  
print(ans)