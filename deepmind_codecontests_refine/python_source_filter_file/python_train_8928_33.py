import collections
import sys
input=sys.stdin.readline

def calc():
  h,w,k=map(int,input().split())
  sy,sx,gy,gx=map(int,input().split())
  sy,sx,gy,gx=sy-1,sx-1,gy-1,gx-1
  board=[input() for _ in range(h)]
  q=collections.deque()
  q.append((sx,sy))
  cost=[[10**18]*w for _ in range(h)]
  cost[sy][sx]=0
  while len(q)!=0:
    x,y=q.popleft()
    c=cost[y][x]
    for i in range(1,k+1):
      if x+i<w and and board[y][x+i]=='.' and c<cost[y][x+i]:
        if cost[y][x+i]>c+1:
          cost[y][x+i]=c+1
          q.append((x+i,y))
      else:
        break
    for i in range(1,k+1):
      if x-i>=0 and board[y][x-i]=='.' and c<cost[y][x-i]:
        if cost[y][x-i]>c+1:
          cost[y][x-i]=c+1
          q.append((x-i,y))
      else:
        break
    for i in range(1,k+1):
      if y+i<h and board[y+i][x]=='.' and c<cost[y+i][x]:
        if cost[y+i][x]>c+1:
          cost[y+i][x]=c+1
          q.append((x,y+i))
      else:
        break
    for i in range(1,k+1):
      if y-i>=0 and board[y-i][x]=='.' and c<cost[y-i][x]:
        if cost[y-i][x]>c+1:
          cost[y-i][x]=c+1
          q.append((x,y-i))
      else:
        break
  if cost[gy][gx]==10**18:
    print(-1)
  else:
    print(cost[gy][gx])
calc()