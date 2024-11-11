def dfs(v):
    global sm, c
    c += 1
    used[v] = True
    sm += len(gr[v])
    for i in gr[v]:
        if not used[i]:
            dfs(i)
n, m, k = map(int, input().split())
st = list(map(int, input().split()))
gr = []
for i in range(n):
    gr.append([])
for i in range(m):
    a, b =map(int, input().split())
    gr[a - 1].append(b - 1)
    gr[b - 1].append(a - 1)
used = [False] * n
it = 0
mx = -1
for i in range(k):
    global sm, c
    c = 0
    sm = 0
    dfs(st[i] - 1)
    it += (c * (c - 1) - sm) // 2
    mx = max(mx, c)
    n -= c
vr = 0

for i in range(len(gr)):
    if not used[i]:
        vr += len(gr[i])
it += ((mx + n) * (n + mx - 1) - mx * (mx - 1)) // 2
print(it - vr // 2)