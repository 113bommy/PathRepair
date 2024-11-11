n, m, k = [int(x) for x in input().split()]
adj = [[] for _ in range(n)]
for _ in range(m):
    u, v = [int(x) for x in input().split()]
    adj[u - 1].append(v - 1)
    adj[v - 1].append(u - 1)
mark = [False for _ in range(n)]
c = [0]
mark[0] = True
while True:
    augmented = False
    for v in adj[c[-1]]:
        if not mark[v]:
            c.append(v)
            augmented = mark[v] = True
            break
    if not augmented:
        break
mark = [False for _ in range(n)]
for v in adj[c[-1]]:
    mark[v] = True
start = 0
for i in range(len(c)):
    if mark[i]:
        start = i
        break
print(len(c) - start)
for i in range(start, len(c)):
    print(c[i] + 1, end=' ')
