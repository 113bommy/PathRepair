from collections import deque
n, m = map(int, input().split())
s = list(map(int, input().split()))
g = [[] for i in range(n)]

for _ in range(m):
    a, b = map(int, input().split())
    a, b = a-1, b-1
    g[a].append(b)
    g[b].append(a)

q = deque()
chk = [0] * n
res = []

for i in range(n):
    tmp = set()
    if not chk[i]:
        q.append(i)
        while q:
            v = q.pop()
            chk[v] = 1
            tmp.add(v)
            for u in g[v]:
                if chk[u] == 1:
                    continue
                q.append(u)
        res.append(tmp)

ans = 0
for re in res:
    tmp2 = set()
    for r in re:
        tmp2.add(s[r] - 1)
    ans += len(tmp2 & re)
print(ans)
