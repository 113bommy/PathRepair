import math
n = int(input())
xy = [list(map(int,input().split())) for i in range(n)]
xy.sort(key = lambda x:math.atan2(x[1],x[0]))
xyrad = [math.atan2(xy[i][1],xy[i][0]) for i in range(n)]
ans = []
x,y = list(zip(*xy))
xsum,ysum = sum(x),sum(y)
eps = 10**-8
for i in range(n):
  xs,ys = 0,0
  for j in range(i,i+n):
    xs += xy[i][0]
    ys += xy[i][1]
    ans.append(math.hypot(xs,ys))
print(max(ans))