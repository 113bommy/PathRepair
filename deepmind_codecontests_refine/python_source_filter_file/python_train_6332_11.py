n, m = map(int, input().split())
p = [int(i) for i in input().split()]
graph = [[] for _ in range(n+1)]
group = [0]*n+1
ans = 0
for _ in range(m):
    x, y = map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)
for i, num in enumerate(p,1):
    space = [i]
    for point in space:
        if group[point]:
            continue
        group[point] = i
        space.extend(graph[point])
    ans += group[num]-group[i]
print(ans)