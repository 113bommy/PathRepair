import sys
input = sys.stdin.readline
from collections import deque

H,W=map(int,input().split())
sh,sw=map(int,input().split())
gh,gw=map(int,input().split())
MAP=[input().strip() for i in range(H)]

ANS=[[1<<30]*W for i in range(H)]

sh-=1
sw-=1
gh-=1
gw-=1

ANS[sh][sw]=0

Q=deque([(sh,sw)])

while Q:
    x,y=Q.popleft()

    for i,j in [(x-2,y-2),(x-2,y-1),(x-2,y),(x-2,y+1),(x-2,y+2),(x-1,y-2),(x-1,y-1),(x-1,y),(x-1,y+1),(x-1,y+2),(x,y-2),(x,y-1),(x,y+1),(x,y+2),(x+1,y-2),(x+1,y-1),(x+1,y),(x+1,y+1),(x+1,y+2),(x+2,y-2),(x+2,y-1),(x+2,y),(x+2,y+1),(x+2,y+2)]:
        if 0<=i<H and 0<=j<W:
            if MAP[i][j]=="." and abs(i-x)+abs(j-y)==1 and ANS[i][j]>ANS[x][y]:
                ANS[i][j]=ANS[x][y]
                Q.append((i,j))
            elif MAP[i][j]=="." and abs(i-x)+abs(j-y)>1 and ANS[i][j]>ANS[x][y]+1:
                ANS[i][j]=ANS[x][y]+1
                Q.append((i,j))

if ANS[gh][gw]==1<<30:
    print(-1)
else:
    print(ANS[gh][gw])

