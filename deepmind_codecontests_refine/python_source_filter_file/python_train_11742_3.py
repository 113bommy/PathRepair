N = int(input())
ab = [tuple(map(int,input().split())) for _ in range(N - 1)]
M = int(input())
uv = [tuple(map(int,input().split())) for _ in range(M)]
route = [[] for _ in range(N)]

for i, (a, b) in enumerate(ab):
    a -= 1
    b -= 1
    route[a].append((b, i))
    route[b].append((a, i))

path = [0] * M
for i, (u, v) in enumerate(uv):
    u -= 1
    v -= 1
    stack = [u]
    visited = [0] * N
    visited[u] = 1
    dire = [[] for _ in range(N)]
    while True:
        s = stack.pop()
        for g, j in route[s]:
            if visited[g]:
                continue   
            stack.append(g)
            dire[g].append((s, j))
            visited[g] = 1
        if visited[v]:
            break
    s = v
    while True:
        g, num = dire[s][0]
        path[i] |= (1 << num)
        if g == u:
            break
        s = g

data = [0] * (1 << M)
ans = 2 ** (N - 1)
for i in range(1, a << M):
    k = len(bin(i)) - 3
    data[i] = data[i - (2 ** k)] | path[k]
    power = bin(data[i]).count("1")
    judge = bin(i).count("1")
    ans += (-2 ** (N - 1 - power) if judge % 2 else 2 ** (N - 1 - power))
print(ans)