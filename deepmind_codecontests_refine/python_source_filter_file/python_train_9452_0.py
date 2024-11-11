import sys
input = sys.stdin.readline

sys.setrecursionlimit(10000000)

N,M,P=map(int,input().split())
INF = 1000000000
edge = []
to = [[] for _ in range(N)]
rto = [[] for _ in range(N)]
reachable_from1 = [False]*N
reachable_fromN = [False]*N
for i in range(M):
    a,b,c = map(int,input().split())
    a-=1
    b-=1
    c=-c
    to[a].append(b)
    rto[b].append(a)
    edge.append([a,b,c])

def dfs(v):
    if reachable_from1[v] == True:
        return
    reachable_from1[v] = True
    for u in to[v]:
        dfs(u)

def rdfs(v):
    if reachable_fromN[v] == True:
        return
    reachable_fromN[v] = True
    for u in rto[v]:
        rdfs(u)

dfs(0)
rdfs(N-1)
ok = [False]*N
for i in range(N):
    ok[i] = reachable_from1[i]&reachable_fromN[i]

d = [INF]*N
d[0] = 0
update = True
step=0
while update:
    update = False
    for i in range(N):
        a,b,c=edge[i]
        if not(ok[a]): continue
        newD = d[a]+c+P
        if newD < d[b]:
            d[b] = newD
            update = True
    step+=1
    if step > N:
        print(-1)
        sys.exit()
print(max(0,-d[N-1]))
    


