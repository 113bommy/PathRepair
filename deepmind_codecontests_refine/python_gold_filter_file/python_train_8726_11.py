H,W,D=map(int,input().split());A=[list(map(int,input().split())) for _ in range(H)];Q=int(input());d=[0]*(H*W+1);g=[0]*(H*W+1)
for i in range(H):
  for j in range(W):d[A[i][j]]=[i,j]
for i in range(1,H*W-D+1):
  g[i+D]=abs(d[i+D][0]-d[i][0])+abs(d[i+D][1]-d[i][1])+g[i]
for q in range(Q):
  l,r=map(int,input().split());print(g[r]-g[l])