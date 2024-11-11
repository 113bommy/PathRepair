n,y=map(int,input().split());r=range
for i in r(n+1):
  for j in r(n-i+1):
      o=n-i-j
      if i*10+j*5+o==y/1000and i+j<=n:print(i,j,o);exit()
print(-1,-1,-1)