import sys
from collections import deque

H,W=map(int,input().split())
si,sj=[int(x)-1 for x in input().split()]
ti,tj=[int(x)-1 for x in input().split()]
A=list(sys.stdin)

dirs=[-2,-1,0,1,2]
dist=[[1000]*W for _ in range(H)]
dist[si][sj]=0
dq=deque()
dq.append((0,si,sj))
ok=False
while dq:
    k,i,j=dq.popleft()
    if k>dist[i][j]:
        continue
    if i==ti and j==tj:
        ok=True
        break
    for di in dirs:
        for dj in dirs:
            if di==dj==0:
                continue
            ni,nj=i+di,j+dj
            if not (0<=ni<H and 0<=nj<W):
                continue
            if A[ni][nj]=='#':
                continue
            if abs(di)+abs(dj)==1:
                append=dq.appendleft
                nk=k
            else:
                append=dq.append
                nk=k+1
            if k>=dist[ni][nj]:
                continue
            dist[ni][nj]=nk
            append((nk,ni,nj))
      
if ok:
    ans=dist[ti][tj]
else:
    ans=-1

print(ans)
