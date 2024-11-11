N,u,v = map(int,input().split())
E = [[] for _ in range(N + 1)]
for i in range(N-1):
    a,b = map(int,input().split())
    E[a].append(b)
    E[b].append(a)
#print(E)
def bfs(start,N):
    d = [-1]*(N+1)
    d[start] = 0
    q = [start]
    while q:
        #print(d,q)
        v = q.pop()
        cnt = d[v]+1
        for i in E[v]:
            if(d[i] == -1):
                q.append(i)
                d[i] = cnt
    return d
taka = bfs(u,N)
aoki = bfs(v,N)
#print(taka,aoki)
for i in range(N+1):
    if(taka[i] < aoki[i]):
        fin = max(fin,aoki[i])
print(fin - 1)