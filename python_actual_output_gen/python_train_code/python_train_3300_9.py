from itertools import combinations


N, K, *XY = map(int, open(0).read().split())
X = sorted(XY[::2])
Y = sorted(XY[1::2])

ans = 10 ** 20
for x1, x2 in combinations(X, 2):
    for y1 in Y[:-1]:
        y2s = sorted(y for x, y in zip(*[iter(XY)] * 2) if x1 <= x <= x2 and y1 <= y)
        if len(y2s) < K:
            continue
        ans = min(ans, (x2 - x1) * (y2s[-1] - y1))
print(ans)

