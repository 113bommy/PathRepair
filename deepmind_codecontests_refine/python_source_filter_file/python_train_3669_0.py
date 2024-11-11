from collections import deque
t = int(input())
for _ in range(t):
    n,m,a,b,c = map(int,input().split())
    g = [[] for i in range(n+5)]
    cost = list(map(int,input().split(" ")))
    cost.insert(0,0)
    cost.sort()
    for i in range(m):
        cost[i+1]+=cost[i]

    for _ in range(m):
        u,v = map(int,input().split(" "))
        g[u].append(v)
        g[v].append(u)

    def BFS(source):
        dis=[-1]*(n+1)
        dis[source]=0
        q = deque([source])
        while(q):
            cur = q.popleft()
            for i in g[cur]:
                if(dis[i]==-1):
                    dis[i] = 1+dis[cur]
                    q.append(i)
        return dis
    dis1 = []
    dis2 = []
    dis3 = []
    dis1.extend(BFS(a))
    dis2.extend(BFS(b))
    dis3.extend(BFS(c))
 
    ans = 2e5
    for i in range(1,n+1):
        temp = dis1[i]+dis2[i]+dis3[i]
        if(temp>m):
            continue
        ans = min(ans,cost[dis2[i]]+cost[temp])
    print(ans)





