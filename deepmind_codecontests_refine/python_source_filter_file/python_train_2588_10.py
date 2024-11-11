import collections
from itertools import product

H, W, N = map(int,input().split())
PaintList = []
pat = list(product((-2,-1,0),repeat=2))
for i in range(N):
  x,y = map(int, input().split())
  for p in pat:
    xw = x + p[0]
    yw = y + p[1]
    #print(xw,yw)
    if 1 <= xw <= H-2 and 1 <= yw <= W-2:
      PaintList.append((xw,yw))

c = collections.Counter(PaintList)
#print(c)
ans = [0] * 10
for k,v in c.items():
  if k[0] <= H-2 and k[1] <= W-2:
    ans[v] += 1
  
ans[0] = (H-2)*(W-2) - sum(ans[1:9])

for i in range(10):
  print(ans[i])