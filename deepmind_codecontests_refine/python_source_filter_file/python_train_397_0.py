from collections import deque;h,w,k=map(int,input().split());m=[input()for _ in[0]*h];v=[[-1]*w for _ in[0]*h];r=9**20
for i in range(h):
 if'S'in m[i]:j=m[i].index('S');q=deque([[i,j]])v[i][j]=0
while q:
 y,x=q.popleft()
 r=min(r,y,x,h-1-y,w-1-x)
 if v[y][x]==k:continue
 for i,j in([1,0],[-1,0],[0,1],[0,-1]):
  t,u=y+i,x+j
  if t>=0and t<h and u>=0and u<w and m[t][u]=='.'and v[t][u]<0:v[t][u]=v[y][x]+1;q.append([t,u])
print(1-(-r//k))