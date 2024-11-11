n, m = map(int, input().split())
b = [[j for j in range(1,n+1) if j != i+1] for i in range(n)]
b.insert(0,[])
t = [[] for i in range(n+1)]

for _ in range(m):
    u, v = map(int, input().split())
    b[u].remove(v)
    b[v].remove(u)
    t[u].append(v)
    t[v].append(u)

def find_shorteset_path(n, start, des, adj):
    queue = [(start,0)]
    visited = [False for i in range(n+1)]
    visited[start] = True
    while queue != []:
        v = queue[0]
        if v[0] == des:
            return v[1]
        for neig in adj[v[0]]:
            if not visited[neig]:
                visited[neig]=True
                queue.append((neig, v[1]+1))
        del queue[0]
        #print(queue)
        #print(visited)
    return False
#print(b)
bus_sol = find_shorteset_path(n, 1, n, b)
#print(t)
train_sol = find_shorteset_path(n, 1, n, t)
if train_sol and bus_sol:
    print(max(train_sol, bus_sol))
else:
    print(-1)