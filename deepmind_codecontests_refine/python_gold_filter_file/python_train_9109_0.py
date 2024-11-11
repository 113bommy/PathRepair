f = lambda: map(int, input().split())
n, a, b, c, d = f()
t = []
for i in range(n):
    x, y = f()
    t.append(((x - a) ** 2 + (y - b) ** 2, (x - c) ** 2 + (y - d) ** 2))
t.sort()
s = 8e14
q = 0
for u, v in reversed(t):
    s = min(s, u + q)
    q = max(q, v)
print(min(s, q))