from collections import deque

H,W=map(int,input().split())
field=[]
spos=deque([])
for i in range(H):
  s=list(input())
  for j in range(W):
    if s[j]=="#":
      spos.append((j,i))
  field.append(s)
  
dx=[1,0,-1,0]
dy=[0,1,0,-1]

ans=-1
while spos:
  for _ in range(len(spos)):
    x,y=spos.popleft()
    for i in range(4):
      nx=x+dx[i]
      ny=y+dy[i]
      if nx<0 or nx>=W or ny<0 or ny>=H:
        pass
      elif field[ny][nx]==".":
        field[ny][nx]="#"
        spos.append((nx,ny))
  ans+=1

print(ans)
