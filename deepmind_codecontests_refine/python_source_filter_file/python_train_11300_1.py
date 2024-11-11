n,m=list(map(int,input().split()))
from collections import defaultdict,deque
g=defaultdict(list)
for i in range(m):
    a,b=list(map(int,input().split()))
    g[a-1].append(b-1)
    g[b-1].append(a-1)



def dfs(x):
    vis[x]=1
    q=deque()
    q.append((x,0))
    while q:
        cur,d=q.popleft()
        
        if maxd[0]<d:
            maxd[0]=d
            maxnode[0]=x
        for i in g[cur]:
            if vis[i]==0:
                q.append((i,d+1))
                vis[i]=1
    
     
    
    
vis=[0]*n
maxd=[0]
maxnode=[0]
dfs(0)
vis=[0]*n
maxd=[0]
dfs(maxnode[0])


print(maxd[0])