import copy
from collections import deque
H,W=map(int, input().split())
A=[[-1]*W for _ in range(H)]
d=deque()
for h in range(H):
  s=input()
  for w in range(W):
    if s[w]=='.':
      pass
    else:
      A[h][w]=0
      d.append((h,w))

DIF=[(1,0),(0,1),(-1,0),(0,-1)]
while d:
  point=d.popleft()
  for dif in DIF:
    x=point[0]+dif[0]
    y=point[1]+dif[1]
    if 0<=x<H and 0<=y<W and A[x][y]==-1:
      d.append((x,y))
      A[x][y]=A[point[0]][point[1]]+1
ans=0    
for h in range(H):
  Amax=max(A[h])
  ans=max(ans,Amax)
#print(A)
print(ans)