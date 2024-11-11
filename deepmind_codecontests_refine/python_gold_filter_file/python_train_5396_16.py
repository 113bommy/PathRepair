H,W=map(int,input().split())
MAP=[list(input()) for i in range(H)]


ANS=0
for i in range(H):
    ANS+=MAP[i].count(".")

from collections import deque

QUE = deque()
QUE.append((0,0))
MAP[0][0]=0

while QUE:
    (x,y)=QUE.pop()

    for i,j in [(x+1,y),(x-1,y),(x,y+1),(x,y-1)]:
        if i<0 or j<0 or i>=H or j>=W:
            continue
        if MAP[i][j]==".":
            MAP[i][j]=MAP[x][y]+1
            QUE.appendleft((i,j))
            
        
if MAP[H-1][W-1]==".":
    print(-1)
else:
    print(ANS-MAP[H-1][W-1]-1)
