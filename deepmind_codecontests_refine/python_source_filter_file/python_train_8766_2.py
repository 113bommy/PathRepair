from itertools import accumulate
x0,y0,ax,ay,bx,by = map(int,input().split())
xs,ys,t0 = map(int,input().split())
pnt = []
x,y = x0,y0
while True:
  if x >= 10**17 or y >= 10**17:
    break
  pnt.append((x,y))
  x,y = (x*ax+bx,y*ay+by)
n = len(pnt)
dist = []
for i in range(1,n):
  xi,yi = pnt[i]
  xp,yp = pnt[i-1]
  dist.append(xi-xp+yi-yp)
ansls = []
for i in range(n):
  t = t0
  xf,yf = pnt[i]
  anstmp = 0
  if abs(xf-xs)+abs(yf-ys) > t:
    ansls.append(anstmp)
    continue
  t -= abs(xf-xs)+abs(yf-ys)
  anstmp += 1
  j = i
  while j > 0 and t >= dist[i-1]:
    anstmp += 1
    t -= dist[i-1]
    j -= 1
  if t >= sum(dist[:i]):
    t -= sum(dist[:i])
    i += 1
    while i < n and t >= dist[i-1]:
      anstmp += 1
      t -= dist[i-1]
      i += 1
  ansls.append(anstmp)
print(max(ansls))