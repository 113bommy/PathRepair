from collections import deque
n,m=map(int,input().split())
g=[[] for _ in range(n)]
for _ in range(m):
    u,v=list(map(int,input().split()))
    g[u-1].append(v-1)
S,T=map(int,input().split())
S-=1;T-=1
INF=10**9
U=[[INF]*n for i in range(3)]
U[0][S]=0
que=deque([(0,S)])
while que:
    t,v=que.popleft()
    u=(t+1)%3
    if t==2:
        U[t][v]+=1
    for w in g[v]:
        if U[u][w]!=INF:
            continue
        que.append((u,w))
        U[u][w]=d
print(U[0][T] if U[0][T]<INF else -1)
