H,W=map(int,input().split())
ch,cw=map(int,input().split())
dh,dw=map(int,input().split())
S=[input() for i in range(H)]
from collections import deque
q=deque([(ch-1,cw-1,0)])
v=[[9999]*W for i in range(H)]
x=((1,0),(-1,0),(0,-1),(0,1))
y=((2,2),(2,1),(2,0),(2,-1),(2,-2),(1,2),(1,1),(1,-1),(1,-2),(0,2),(0,-2),(-1,2),(-1,1),(-1,-1),(-1,-2),(-2,2),(-2,1),(-2,0),(-2,-1),(-2,-2))
while q:
    h,w,d=q.popleft()
    for i,j in x:
        if 0<=h+i<H and 0<=w+j<W and S[h+i][w+j]=='.' and d<v[h+i][w+j]:
            v[h+i][w+j]=d
            q.appendleft((h+i,w+j,d))
    for i,j in y:
        if 0<=h+i<H and 0<=w+j<W and S[h+i][w+j]=='.' and d+1<v[h+i][w+j]:
            v[h+i][w+j]=d+1
            q.append((h+i,w+j,d+1))
print(v[dh-1][dw-1] if v[dh-1][dw-1]<9999 else -1)