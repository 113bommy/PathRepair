def solve():
    n, m = map(int, input().split())
    edges = []
    adj = [[] for _ in range(n)]
    indeg = [0] * n
    for _ in range(m):
        t, x, y = map(int, input().split())
        x -= 1
        y -= 1
        edges.append((x, y))
        if t == 1:
            adj[x].append(y)
            indeg[y] += 1
    q = [i for i in range(n) if indeg[i]==0]
    count = 0
    order = [0] * n
    while q:
        top = q.pop()
        order[top] = count
        count += 1
        for nei in adj[top]:
            indeg[nei] -= 1
            if indeg[nei] == 0:
                q.append(nei)
    if count < n:
        print("NO")
        return
    print("YES")
    for x, y in edges:
        if order[x] > order[y]:
            x, y = y, x
        print(x, y)
        
        

t = int(input())

for _ in range(t):
    solve()
