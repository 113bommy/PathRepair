from collections import deque
h,w=map(int,input().split())
a=[list(input()) for i in range(h)]
q=deque()

for i in range(h):
    for j in range(w):
        if a[i][j]=='#':
            q.append((i,j))

ans=0
while q:
    nq=deque()
    while True:        
        y,x=q.popleft()
        for dy,dx in ((1,0),(-1,0),(0,1),(0,-1)):
            ny=dy+y
            nx=dx+x
            if 0<=ny<h and 0<=nx<w and a[ny][nx]!='#':
                a[ny][nx]='#'
                nq.append((ny,nx))
        if not q:
            ans+=1
            q=nq
            break
print(ans-1)
    