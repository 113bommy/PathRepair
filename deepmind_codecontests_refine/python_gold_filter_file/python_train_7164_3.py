n,m,qu=map(int,input().split())
ans=[[0]*(n+1) for __ in range(n+1)]
for _ in range(m):
  l,r=map(int,input().split())
  ans[l][r]+=1
for i in range(n+1):
  for j in range(n):
    ans[i][j+1]+=ans[i][j]
for i in range(n):
  for j in range(n+1):
    ans[i+1][j]+=ans[i][j]
for qq in range(qu):
  p,q=map(int,input().split())
  print(ans[q][q]-ans[p-1][q]-ans[q][p-1]+ans[p-1][p-1])
