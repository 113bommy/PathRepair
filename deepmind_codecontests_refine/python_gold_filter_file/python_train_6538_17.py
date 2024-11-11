h,w=map(int,input().split())
a=['*'*(w+2)]+['*'+input()+'*' for _ in range(h)]+['*'*(w+2)]
from collections import deque
d=deque()
c=[[0]*w for _ in range(h)]
for i in range(1,h+1):
  for j in range(1,w+1):
    if a[i][j]=='#':
      d.append([i,j])
di=[[0,1],[1,0],[-1,0],[0,-1]]
while d:
  g=d.popleft()
  for i in di:
    x=g[0]+i[0]
    y=g[1]+i[1]
    if a[x][y]=='.':
      if c[x-1][y-1]==0:
        d.append([x,y])
        c[x-1][y-1]=c[g[0]-1][g[1]-1]+1
m=0
for i in range(h):
  for j in range(w):
    m=max(m,c[i][j])
print(m)