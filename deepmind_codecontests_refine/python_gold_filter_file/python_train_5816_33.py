import sys
import heapq as h
stdin = sys.stdin

ni = lambda: int(ns())
nl = lambda: list(map(int, stdin.readline().split()))
nm = lambda: map(int, stdin.readline().split())
ns = lambda: stdin.readline().rstrip()

def dist(p,q):
  px,py,pr = p
  qx,qy,qr = q
  d = ((px-qx)**2 + (py-qy)**2)**.5
  return max(d-(pr+qr),0)
  
  

xs,ys,xt,yt = nm()
n = ni()
pl = [(xs,ys,0)] + [tuple(nm()) for _ in range(n)] + [(xt,yt,0)]
gr = [dict() for _ in range(n+2)]
for i in range(n+1):
  for j in range(i+1,n+2):
    gr[i][j] = dist(pl[i],pl[j])
    gr[j][i] = gr[i][j]

dis = [float("inf")]*(n+2)
q = [(0,0)]
while q:
  d,v = h.heappop(q)
  if dis[v] <= d:
    continue
  dis[v] = d
  for x in gr[v]:
    if dis[x] > dis[v]+gr[v][x]:
      h.heappush(q,(dis[v]+gr[v][x],x))
print(dis[-1])

