import sys
inf=1000002
sys.setrecursionlimit(inf)
from collections import deque
h,w,k=map(int,input().split())
x1,y1,x2,y2=map(int,input().split())
c=[input() for i in range(h)]
dp=[[inf if c[i][j]=="." else -1 for j in range(w)] for i in range(h)]
now=deque([x1-1,y1-1])
dp[x1-1][y1-1]=0
def bfs(d):
    global dp,now
    l=len(now)
    if l==0:
        return
    dp_sub=deque()
    cand=set()
    for i in range(l):
        x,y=now.popleft()
        for j in range(1,min(k+1,w-y)):
            if dp[x][y+j]==inf:
                dp_sub.append([x,y+j,d])
                cand.add((x,y+j))
            else:
                break
        for j in range(1,min(k+1,y+1)):
            if dp[x][y-j]==inf:
                dp_sub.append([x,y-j,d])
                cand.add((x,y-j))
            else:
                break
        for j in range(1,min(k+1,h-x)):
            if dp[x+j][y]==inf:
                dp_sub.append([x+j,y,d])
                cand.add((x+j,y))
            else:
                break
        for j in range(1,min(k+1,x+1)):
            if dp[x-j][y]==inf:
                dp_sub.append([x-j,y,d])
                cand.add((x-j,y))
            else:
                break
    while dp_sub!=deque([]):
        e=dp_sub.popleft()
        dp[e[0]][e[1]]=e[2]
    for i in cand:
        now.append(i)
    bfs(d+1)
bfs(1)
print(dp[x2-1][y2-1] if dp[x2-1][y2-1]!=inf else -1)