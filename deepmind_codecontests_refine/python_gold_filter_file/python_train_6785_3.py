from collections import deque


input()
h = [list(bin(int(i)))[2:] for i in input().split()]
sas = min(map(len, h))
ans = 1e9
graf = [[] for _ in range(100000)]
rebra = []
def bfs(assx, sasx):
    q = deque()
    q.append(assx)
    metka = [1 for _ in range(100000)]
    metka[assx] = 0
    dis = [0 for _ in range(100000)]
    while q:
        x = q.popleft()
        for i in graf[x]:
            if i == sasx and x != assx:
                return dis[x] + 2
            if metka[i] and (i != sasx or x != assx):
                metka[i] = 0
                dis[i] = dis[x] + 1
                q.append(i)
    return 0
for i in range(len(h)):
    h[i].reverse()
for i in range(60):
    r = 0
    ass = []
    for j in range(len(h)):
        if len(h[j]) <= i:
            continue
        if int(h[j][i]):
            r += 1
            ass.append(j)
    if r >= 3:
        print(3)
        exit()
    if len(ass) > 1:
        graf[ass[0]].append(ass[1])
        graf[ass[1]].append(ass[0])
        rebra.append(ass)
for i in rebra:
    g = bfs(i[0], i[1])
    if g:
        ans = min(ans, g)
print(ans if ans != 1e9 else -1)
