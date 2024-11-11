from collections import deque

def clamp(a,b,c):
  return min(max(a,b),c)

H,W = map(int,input().split())
A = [input() for _ in range(H)]

D = [[-1]*W for _ in range(H)]
dd = [(1,0),(-1,0),(0,1),(0,-1)]
Q = deque()
res = 0

for i in range(H):
  for j in range(W):
    if A[i][j] == "#":
      D[i][j] = 0
      Q.append([i,j,0])
      
while len(Q)>0:
  x,y,n = Q.popleft()
  for dx,dy in dd:
    xx = clamp(x+dx,0,H-1)
    yy = clamp(y+dy,0,W-1)
    if D[xx][yy] == -1:
      D[xx][yy] = n+1
      Q.append([xx,yy,n+1])
      res = n+1
      
print(res)