import sys

n,m = map(int, sys.stdin.readline().strip().split())
edges=[[] for _ in range(n)]
for i in range(m):
    x,y = map(int, sys.stdin.readline().strip().split())
    edges[x-1].append(y)
    edges[y-1].append(x)

ans = 0
visited = [False]*(n)
for i in range(n):
    if visited[i]:
        continue
    cycle = True
    stack = [i]
    visited[i-1] = True
    while stack:
        vertex = stack.pop()
        if len(edges[vertex-1])!=2:
            cycle = False
        for j in edges[vertex-1]:
            if not visited[j-1]:
                visited[j-1] = True
                stack.append(j)

    ans += int(cycle)
print(ans)