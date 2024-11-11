towns, railways = [int(x) for x in input().split()]
u = [[] for x in range(towns+1)]
t = [[] for x in range(towns+1)]

for i in range(railways):
    [a,b] = [int(x) for x in input().split()]
    u[a].append(b)
    u[b].append(a)
    
for i in range(1,towns+1):
    for j in range(i+1,towns+1):
        if j not in u[i]:
            t[i].append(j)
            t[j].append(i)

def bfs(g,n):
    q = [1]
    vis = [1 for x in range(n+1)]
    dis = [0 for x in range(n+1)]
    while len(q):
        cur = q[0]
        q.remove(cur)
        for i in g[cur]:
            if vis[i]:
                q.append(i)
                vis[i] = 0
                dis[i] = dis[cur]+1
                if(i == n):
                    return dis[n]
    return -1
            
     
if towns in u[0]:
    print(bfs(t,towns))
else:
    print(bfs(u,towns))