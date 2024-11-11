from bisect import bisect_right
n, m, k, t = map(int, input().split())
r = ['Carrots', 'Kiwis', 'Grapes']
r = r[(m + 1) % 3: ] + r[: (m + 1) % 3]
p = [m * x + y for x, y in (map(int, input().split()) for i in range(k))]
p.sort()
q = [0] * t
for i in range(t):
    x, y = map(int, input().split())
    j = m * x + y
    d = bisect_right(p, j)
    if p[d - 1] == j: q[i] = 'Waste'
    else: q[i] = r[(j - d) % 3]       
print('\n'.join(q))