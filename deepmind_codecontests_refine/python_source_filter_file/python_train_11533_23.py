from collections import deque
h,w=map(int,input().split())
ch,cw=map(int,input().split())
dh,dw=map(int,input().split())

maze = [list(input()) for i in range(h)]
ans = [[-1]*w for i in range(h)]

dx=[0,1,0,-1]
dy=[1,0,-1,0]

ans[ch-1][cw-1]=0
def bfs(ans):
  qu = deque([])
  qu.append([cw-1,ch-1])
  while qu:
    zahyou=qu.popleft()
    x=zahyou[0]
    y=zahyou[1]
    for i in range(4):
      if 0 <= x+dx[i] < w and 0 <= y+dy[i] < h:
        if maze[y+dy[i]][x+dx[i]]=="." and (ans[y+dy[i]][x+dx[i]]>ans[y][x] or ans[y+dy[i]][x+dx[i]]==-1):
          qu.append([x+dx[i],y+dy[i]])
          ans[y+dy[i]][x+dx[i]] = ans[y][x]
    for i in range(x-2,x+3):
      for j in range(y-2,y+3):
        if 0<=i<w and 0<=j<h:
          if maze[j][i]=="." and (ans[j][i]>ans[y][x]+1 or ans[j][i]==-1):
            ans[j][i]=(ans[y][x]+1)
            qu.append([i,j])

bfs(ans)
print(ans[dh-1][dw-1])
  