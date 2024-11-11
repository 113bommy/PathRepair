n = int(input())
p = [[] for i in range(n + 1)]
for j in range(n - 1):
    a, b = map(int, input().split())
    p[a].append(b)
    p[b].append(a)

def g(b, c):
    x = y = d = 0
    for a in p[b]:
        if a != c:
            s, z = g(a, b)
            z, y, x = sorted([x, y, z])
            d = max(d, s)
    return max(d, x + y), x + 1

print(max(g(a, b)[0] * g(b, a)[0] for a in range(n + 1) for b in p[a] if b > a))
