f = lambda: map(int, input().split())
n, m = f()
k = n + 1
s = [[0] * k for i in range(k)]
for j in range(m):
    u, v = f()
    s[u][v] = s[v][u] = 1
d = [-1] * k
d[1] = 0
q = [1]
while q:
    u = q.pop(0)
    for v in range(1, k):
        if s[u][v] != s[1][n] and d[v] == -1:
            d[v] = d[u] + 1
            q.append(v)
print(d[n])
