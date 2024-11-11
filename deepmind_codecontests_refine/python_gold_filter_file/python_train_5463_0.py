f = lambda: map(int, input().split())
n, m, k = f()
p = [0] * m
d, x = -1, 0
q = [[] for i in range(m)]
for y in range(n):
    t = list(f())
    s = 0
    for a, b in zip(q, t):
        while a and a[-1][0] < b: a.pop()
        a.append((b, y))
        s += a[0][0]
    if s > k:
        while s > k:
            s = 0
            for a in q:
                if a and a[0][1] == x: a.pop(0)
                if a: s += a[0][0]
            x += 1
    elif d < y - x:
        d = y - x
        p = [a[0][0] for a in q]
for i in p: print(i)