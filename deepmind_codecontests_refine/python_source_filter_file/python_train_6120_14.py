from math import hypot
from collections import deque

N, K, *XYC = map(int, open(0).read().split())
XYC = list(zip(*[iter(XYC)] * 3))

Q = deque([(0, 0, 1000.0)])

ans = float("inf")
while Q:
    X, Y, r = Q.popleft()
    if ans * 0.9999999 > sorted(c * hypot(max(abs(X - x) - r, 0), max(abs(Y - y) - r, 0)) for x, y, c in XYC)[K - 1]:
        ans = min(ans, sorted(c * hypot(X - x, Y - y) for x, y, c in XYC)[K - 1])
        for dx, dy in [(-0.5, -0.5), (-0.5, 0.5), (0.5, -0.5), (0.5, 0.5)]:
            Q.append((X + dx * r, Y + dy * r, r / 2))

print(ans)