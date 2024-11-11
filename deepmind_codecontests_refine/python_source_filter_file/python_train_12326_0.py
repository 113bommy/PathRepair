n, t = int(input()), list(map(int, input().split()))
a, b = {}, {}
for i, j in enumerate(t):
    if not j in a: a[j] = i
    else: b[j] = i
p = [(a[j], b[j] - 1) for j in b]
s = [j if j > 0 else 0 for j in t]
u = v = 2 * t[p[0][0]] - 1
for i in range(n - 1): s[i + 1] += s[i]
for i, j in p:
    u = 2 * t[i] + s[j] - s[i]
    if u > v: a, b, v = i, j, u
s = list(range(1, a + 1)) + [i for i, j in enumerate(t[a + 1: b], a + 2) if j < 0] + list(range(b + 3, n + 1))
print(v, len(s))
print(' '.join(map(str, s)))