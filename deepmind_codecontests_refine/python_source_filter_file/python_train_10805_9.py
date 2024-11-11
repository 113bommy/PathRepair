import sys
sys.setrecursionlimit(10**7)
def dfs(now):
  res=day[now]
  if vis[now]:
    if res==-1:return -1
    else:return res
  res=1
  vis[now]=1
  for to in d[now]:
    r=dfs(to)
    if r==-1:return -1
    res=max(res,r+1)
  day[now]=res
  return res
n=int(input())
v=0
si=[[0]*n for _ in range(n)]
for i in range(n):
  for j in range(i+1,n):
    si[i][j]=v
    v+=1
d=[[] for _ in range(v)]
s=[]
for i in range(n):
  a=list(map(int,input().split()))
  if i<a[0]-1:b=si[i][a[0]-1]
  else:b=si[a[0]-1][i]
  for j in a[1:]:
    j-=1
    if i<j:
      d[b]+=[si[i][j]]
      b=si[i][j]
    else:
      d[b]+=[si[j][i]]
      b=si[i][j]
vis=[0]*v
day=[-1]*v
ans=0
for i in range(v):
  di=dfs(i)
  if di==-1:
    print(-1)
    exit()
  ans=max(ans,di)
print(ans)