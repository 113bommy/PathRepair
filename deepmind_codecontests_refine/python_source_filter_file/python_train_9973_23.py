import math
pi = math.atan(1) * 4
N = int(input())
X = []
for _ in range(N):
    x, y = map(int, input().split())
    if x == y == 0: continue
    if x == 0:
        r = pi/4 if y > 0 else -pi/4
    else:
        r = math.atan(y/x)
        if x < 0: r += pi/2
    X.append((x, y, r))

X = sorted(X, key = lambda x: x[2]) * 2
M = len(X)
ma = 0
for i in range(M):
    sx, sy = 0, 0
    for j in range(i+1, min(i+M//2+1, M)):
        sx += X[j][0]
        sy += X[j][1]
        d = sx ** 2 + sy ** 2
        ma = max(ma, d)

print(ma**0.5)