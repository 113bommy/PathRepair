from collections import*
h,w=map(int,input().split())
c=eval('list(input()),'*h)
q=deque()
for i in range(h):
    for j in range(w):
        if c[i][j]=='#':
            q.append((i,j,0))
ans=0
while q:
    y,x,v=q.popleft()
    ans=max(ans,v)
    for i,j in((y,x-1),(y,x+1),(y-1,x),(y+1,x)):
        if h>i>=0 and w>j>=0 and c[i][j]=='.':
            c[i][j]='#'
            q.append((i,j,v+1))
print(ans)