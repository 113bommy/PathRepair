from heapq import *
N,M=map(int,input().split())
G=[[] for i in range(N)]
for i in range(N-1):
  G[i+1].append((i,0))
l,r,c=0,0,0
for i in range(M):
  l,r,c=map(int,input().split())
  G[l-1].append((r-1,c))
D=[0]*N
INF=10**20
def ijk(s):
  global D,INF,G
  for i in range(len(G)):
    D[i]=INF
  D[s]=0
  Q=[]
  heapify(Q)
  heappush(Q,(0,s))
  p,v,e=0,0,0
  while len(Q):
    p=heappop(Q)
    v=p[1]
    if D[v]<p[0]:
      continue
    for i in range(len(G[v])):
      e=G[v][i]
      if D[e[0]]>D[v]+e[1]:
        D[e[0]]=D[v]+e[1]
        heappush(Q,(D[e[0]],e[0]))

ijk(0)
if D[-1]>=INF:
  print(-1)
else:
  print(D[-1])