from collections import deque

h,w=map(int,input().split())
a = [input() for _ in range(h)]
move=((1,0),(0,1),(-1,0),(0,-1))

que=deque([])
visited=[[0]*h for _ in range(w)]
for i in range(h):
    for j in range(w):
        if a[i][j]=="#":
            que.append((i,j,0))
            visited[i][j]==1


while len(que)>0:       
    ci,cj,d=que.popleft()
    for mi,mj in move:
        ni,nj=mi+ci,mj+cj
        if 0<=ni<h and 0<=nj<w and visited[ni][nj]==0:
            if a[ni][nj]==".":
                visited[ni][nj]=1
                que.append((ni,nj,d+1))

print(d)