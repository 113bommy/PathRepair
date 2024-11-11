from collections import defaultdict

n, m = map(int, input().split())
c = list(map(int, input().split()))

res = defaultdict(set)
for _ in range(m):
    u, v = map(lambda x: int(x) - 1, input().split())
    if c[u] != c[v]:
        res[c[u]].add(c[v])
        res[c[v]].add(c[u])

res_count = 0
res_color = -1
for color in c:
    count = res[color]
    if res_count == 0 or res_count < len(count):
        res_count = len(count)
        res_color = color
    elif res_count == len(count) and color < res_color:
        res_color = color

print(res_color)