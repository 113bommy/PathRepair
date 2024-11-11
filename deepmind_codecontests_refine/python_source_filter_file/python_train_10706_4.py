n = int(input())
edges = [[] for _ in range(n)]

for _ in range(n-1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    edges[a].append(b)
    edges[b].append(a)

def bfs(v):
    q = []
    depth = [n]*n
    q.append(v)
    depth[v] = 0
    i = 0
    while i < len(q):
        x = q[i]
        d = depth[x]
        for e in edges[x]:
            if depth[e] == n:
                depth[e] = d+1
                q.append(e)
        i += 1
    return depth

d1 = bfs(0)
d2 = bfs(n-1)

c = 0
for i in range(n):
    if d1[i] <= d2[i]:
        c += 1
if 2*c > n:
    print("Fennec")
else:
    print("Sunuke")
