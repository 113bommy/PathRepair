f = lambda: list(map(int, input().split()))

def g(t):
    n = t[0]
    t[0] = 0
    for i in range(1, n): t[i + 1] += t[i]
    p = [t[n]] * (n + 1)
    p[n] = 0
    for d in range(1, n):
        p[d] -= min(t[j + d] - t[j] for j in range(n - d + 1))
    p.reverse()
    return p

def h(u):
    v = g(f())
    p = [0] * (min(m, len(u) + len(v)) + 1)
    for i, x in enumerate(u):
        for j, y in enumerate(v):
            if i + j > m: break
            p[i + j] = max(p[i + j], x + y)
    return p

n, m = f()
u = g(f())
for i in range(n - 1): u = h(u)
print(u[-1])