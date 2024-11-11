import itertools

n, k = map(int, input().split())
xy = [tuple(map(int, input().split())) for i in range(n)]
ans = float("INF")
for a, b in itertools.combinations(xy, 2):
    for c, d in itertools.combinations(xy, 2):
        x1, x2 = a[0], b[0]
        y1, y2 = c[1], d[1]
        count = 0
        for x, y in xy:
            if min(x1, x2) <= x <= max(x1, x2) and min(y1, y2) <= y <= max(y1, y2):
                count += 1
        if count >= k:
            ans = min(ans, abs(x1 - x2) * abs(y1 - y2))
print(ans)