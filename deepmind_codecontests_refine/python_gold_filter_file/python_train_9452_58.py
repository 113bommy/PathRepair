import sys
sys.setrecursionlimit(10**9)

def BF(edges,n,s):
    inf=float("inf")
    d=[inf for i in range(n+1)]
    d[s]=0
    update=True
    for i in range(n+1):
      update=False
      for v,u,cost in edges:
        if cand[v]!=1 or cand[u]!=1:
          continue
        if d[v]!=inf and d[u]>d[v]+cost:
          d[u]=d[v]+cost
          update=True
      if update==False:
        break
      if i==n:
        return inf
    return -d[-1]

def DFS_1toN(v):
  for u in to[v]:
    if toflag[u]==0:
      toflag[u]=1
      DFS_1toN(u)
      
def DFS_Nto1(v):
  for u in ot[v]:
    if otflag[u]==0:
      otflag[u]=1
      DFS_Nto1(u)
    
n,m,p=map(int,input().split())
g=[]
to=[[] for _ in range(n+1)]
ot=[[] for _ in range(n+1)]
for _ in range(m):
  a,b,c=map(int,input().split())
  g.append([a,b,-(c-p)])
  to[a].append(b)
  ot[b].append(a)
toflag=[0]*(n+1)
toflag[1]=1
DFS_1toN(1)
otflag=[0]*(n+1)
otflag[n]=1
DFS_Nto1(n)
cand=[0]*(n+1)
for i in range(1,n+1):
  cand[i]=toflag[i]*otflag[i]
ans=BF(g,n,1)
if ans==float('inf'):
  print(-1)
else:
  print(max(ans,0))