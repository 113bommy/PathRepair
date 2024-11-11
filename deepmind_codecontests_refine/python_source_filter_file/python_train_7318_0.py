f = lambda: map(int, input().split())

n, m = f()
u = []
for i in range(n - 1):
    t = list(f())
    n = t[0]
    for i in range(1, n): t[i + 1] += t[i]
    v = [t[n]] * (n + 1)
    v[0] = t[0] = 0
    for d in range(1, n):
        v[n - d] -= min(t[j + d] - t[j] for j in range(n - d + 1))
    if u:
        p = [0] * (min(m, len(u) + len(v)) + 1)
        for i, x in enumerate(u):
            for j, y in enumerate(v, i):
                if j > m: break
                p[j] = max(p[j], x + y)
        u = p
    else:
        u = v

print(u[m])