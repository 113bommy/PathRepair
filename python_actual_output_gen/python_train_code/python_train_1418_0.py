n, m = map(int, input().split())
s, p = 0, [[] for i in range(n + 1)]
t = list(map(int, input().split()))
for i in range(m - 1):
    if t[i] != t[i + 1]:
        p[t[i + 1]].append(t[i])
        p[t[i]].append(t[i + 1])
for i, q in enumerate(p):
    if q:
        q.sort()
        k = q[len(q) // 2]
        d = sum(abs(i - j) - abs(k - j) for j in q)
        if d > s: s = d
print(sum(abs(t[i + 1] - t[i]) for i in range(m - 1)) - d)