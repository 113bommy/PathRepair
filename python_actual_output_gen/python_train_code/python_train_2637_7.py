N, M = map(int, input().split())
g = [[] for _ in range(M + 1)]
for _ in range(M):
    a, b = map(int, input().split())
    g[a].append(b)
    g[b].append(a)

ans = 0
def walk(cur, visited):
    global ans
    tmp = visited + [cur]
    if len(tmp) == N:
        ans += 1
    for nex in g[cur]:
        if nex not in tmp:
            walk(nex, tmp)
walk(1, [])
print(ans)