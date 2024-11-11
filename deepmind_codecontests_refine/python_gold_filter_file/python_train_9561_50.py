import itertools

n, k = map(int, input().split())
xy = [tuple(map(int, input().split())) for i in range(n)]
ans = float("INF")
for a, b in itertools.combinations(xy, 2):
    for c, d in itertools.combinations(xy, 2):
        x1, x2 = sorted([a[0], b[0]])
        y1, y2 = sorted([c[1], d[1]])
        count = 0
        for x, y in xy:
            if x1 <= x <= x2 and y1 <= y <= y2:
                count += 1
        if count >= k:
            ans = min(ans, (x2 - x1) * (y2 - y1))
print(ans)