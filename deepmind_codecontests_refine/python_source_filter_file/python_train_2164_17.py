import sys,heapq
input = sys.stdin.buffer.readline

n,m,s = map(int,input().split())
if s >= 2500:
    s = 2499

dg = 2500
INF = 10**12

dist = [INF]*(n*dg)

edge = [[] for i in range(n)]
a = [0]*m
b = [0]*m

for i in range(m):
    u,v,aa,bb = map(int,input().split())
    a[i] = aa
    b[i] = bb
    edge[u-1].append( (i,v-1))
    edge[v-1].append( (i,u-1) )


c = [0]*n
d = [0]*n

for i in range(n):
    cc,dd = map(int,input().split())
    c[i] = cc
    d[i] = dd

tank = [(0,s)]
nonused = [True]*(n*dg)


while tank:
    tim,fr = heapq.heappop(tank)
    if dist[fr] != INF:
        continue
    dist[fr] = tim
    pos,mon = divmod(fr,dg)

    for idx,go in edge[pos]:
        if mon >= a[idx] and dist[go*dg + mon-a[idx]] == INF:
            heapq.heappush(tank,(tim + b[idx] ,go*dg + mon-a[idx] ))
    if mon + c[pos] < dg and dist[fr + c[pos]] == INF:
        heapq.heappush(tank,(tim + d[pos] ,fr + c[pos] ))

for i in range(1,n):
    res = INF
    for j in range(dg):
        if dist[i*dg+j] < res:
            res = dist[i*dg+j]
    print(res)

