import sys
sys.setrecursionlimit(2000)
#print(sys.getrecursionlimit())
n,m=map(int,input().split())
dp=[-1]*n
E=[ [] for i in range(n) ]

for i in range(m):
  x,y=map(int,input().split())
  x-=1
  y-=1
  E[x].append(y)

def rec(v):
  if dp[v]!=-1:return dp[v]
  res=0
  for nv in E[v]:
    res=max(res,rec(nv)+1)
  dp[v]=res
  return res

res=0
for v in range(n):
  res=max(res,rec(v))
print(res)