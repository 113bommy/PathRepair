from heapq import heappush,heappop 
from math import sqrt
inf=float("inf")

xs,ys,xt,yt=map(int,input().split())
n=int(input())

q=[]
l=[(xs,ys,0),(xt,yt,0)]+[tuple(map(int,input().split())) for _ in range(n)]

sizeV=len(l)
rests={*range(sizeV)}
cost=[inf]*sizeV
cost[0]=0
heappush(q,(0,0))

while q:
  c1,i=heappop(q)
  if c1>cost[i]:continue

  rests.remove(i)
  if not rests:break

  xi,yi,ri=l[i]
  for j in rests:
    xj,yj,rj=l[j]
    d=max(0,sqrt((xj-xi)**2+(yj-yi)**2)-ri-rj)
    c2=c1+d
    if c2<cost[j]:
      cost[j]=c2
      heappush(q,(c2,j))

print(cost[1])