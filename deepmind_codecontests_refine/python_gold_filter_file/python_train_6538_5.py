from collections import deque

H,W=map(int,input().split())
S=[input() for _ in range(H)]

paint=((1,0),(-1,0),(0,1),(0,-1))
que=deque([])

dark=[[0]*W for _ in range(H)] # 1が黒、0はまだ白

for i in range(H): # 初期化(最初に黒いマスをdarkリストに入れて、キューに入れる。)
    for j in range(W):
        if S[i][j]=='#':
            que.append((i,j,0))
            dark[i][j]=1
ans=0
while len(que)>0:
    di,dj,c=que.popleft()
    
    for pi,pj in paint:
        ni,nj=pi+di,pj+dj # 移動先がni,nj
        if 0<=ni<H and 0<=nj<W and dark[ni][nj]==0:
            dark[ni][nj]=1
            que.append((ni,nj,c+1))
            ans=c+1
print(ans)