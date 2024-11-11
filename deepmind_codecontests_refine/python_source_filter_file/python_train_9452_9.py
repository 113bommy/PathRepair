import sys

sys.setrecursionlimit(10000)

n, m, p = list(map(int, input().split()))
abc = [list(map(int, input().split())) for _ in range(m)]
al = [[] for _ in range(n)]

for i in range(m):
    abc[i][0] -= 1
    abc[i][1] -= 1
    abc[i][2] = -(abc[i][2] - p)

for a, b, c in abc:
    al[a].append(b)

d = [1e9] * n
d[0] = 0

for _ in range(n - 1):
    for u, v, c in abc:
        if d[v] > d[u] + c:
            d[v] = d[u] + c

res = -d[-1]

for _ in range(n - 1):
    for u, v, c in abc:
        if d[v] > d[u] + c:
            d[v] = d[u] + c
    

if res != -d[-1]:
    print(-1)
else:
    print(max(res, 0))
