from itertools import combinations as cc
l = []
n,k = map(int, input().split())
xs,ys = set(),set()
t = 10**24
for _ in range(n):
  x,y = map(int, input().split())
  xs.add(x)
  ys.add(y)
  l.append((x,y))
xs = sorted(list(xs))
ys = sorted(list(ys))
for xl,xr in cc(xs,2):
  for yl,yr in cc(ys,2):
    cnt = 0
    for x,y in l:
      if xl<=x<=xr and yl<=y<=yr:
        cnt += 1
      if cnt >= k:
        s = (xr-xl)*(yr-yl)
        if t > s:
          t = s
print(t)