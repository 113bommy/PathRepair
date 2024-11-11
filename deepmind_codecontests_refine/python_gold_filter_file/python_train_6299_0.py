from queue import Queue

n,m=map(int,input().split())
g=[[]for i in range(n)]
g1=[[]for i in range(n)]
for i in range(m):
    a,b=map(int,input().split())
    g[a-1].append(b-1)
    g[b-1].append(a-1)
for i in range(n-1):
    for j in range(i+1,n):
        if j not in g[i]:
            g1[i].append(j)
            g1[j].append(i)
un=float('inf')
def bfs(g):
    q=Queue(maxsize = n)
    q.put(0)
    #dist=[0]+[un]*(n-1)
    while not q.empty():
        curr=q.queue[0]
        q.get()
        for j in g[curr]:
            if dist[j]==un:
                dist[j]=dist[curr]+1
                q.put(j)
    return dist[n-1]
dist=[0]+[un]*(n-1)
r=[]
y=bfs(g)

dist=[0]+[un]*(n-1)
z=bfs(g1)
r.extend([y,z])

if un in r:
    print(-1)
else:
    print(max(r))
        
    