f = lambda: input().split()
n, m, k = map(int, f())
u = list(range(n + 1))
v = [n] * n
s = {q: i for i, q in zip(u, f())}
p = ['YES'] * m

def g(i):
    k = u[i]
    while k != u[k]: k = u[k]
    while u[i] != k: i, u[i] = u[i], k
    return k

for l in range(m):
    r, x, y = f()
    i, j = s[x], s[y]
    a, b = g(i), g(j)
    i, j = v[a], v[b]
    c, d = g(i), g(j)
    if r == '2': b, d = d, b
    if a == d: p[l] = 'NO'
    elif c == b == n: v[a], v[d] = d, a
    elif c == b: p[l] = 'NO'
    elif c == n: u[a] = b
    elif b == n: u[d] = c
    elif d == n: u[b] = a
    else: u[a], u[c] = b, d

u = [g(q) for q in u]
v = [u[q] for q in v]

for l in range(k):
    x, y = f()
    i, j = s[x], s[y]
    a, c = u[i], u[j]
    p.append(str(3 - 2 * (a == c) - (a == v[c])))

print('\n'.join(p))