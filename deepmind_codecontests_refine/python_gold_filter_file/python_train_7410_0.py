n, m = map(int, input().split())
 
AE = []
E = [[] for _ in range(n)]
di = [0]*n
do = [0]*n
ok = True
 
def DFS(u):
    global ok
    
    di[u] = True
    for v in E[u]:
        if di[v]:
            if not do[v]:
                ok = False
            continue
        DFS(v)
    do[u] = True
 
for _ in range(m):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    
    AE.append((u,v) )
    E[u].append(v)
 
for i in range(n):
    if not di[i]:
        DFS(i)

if ok:
    print(1)
    for _ in range(m):
        print(1, end=' ')
else:
    print(2)
    for u,v in AE:
        print(int(u < v) + 1, end=' ')