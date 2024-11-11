g = lambda: map(int, input().split())
n, m, k = g()
F, T = [], []
e = int(1e9)

for i in range(m):
    d, f, t, c = g()
    if f: F.append((d, f, c))
    else: T.append((-d, t, c))

for p in [F, T]:
    C = [e] * (n + 1)
    s = n * e
    q = []

    p.sort()
    for d, t, c in p:
        if C[t] > c:
            s += c - C[t]
            C[t] = c
            if s < e: q.append((s, d))
    p.clear()
    p += q

s, t = e, (0, 0)
for f in F:
    while f:
        if t[1] + f[1] + k < 0: s = min(s, f[0] + t[0])
        elif T:
            t = T.pop()
            continue
        f = 0

print(s if s < e else -1)