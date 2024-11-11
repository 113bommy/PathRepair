N, K = map(int, input().split())
XY = [list(map(int, input().split())) for _ in range(N)]
X, Y = zip(*XY)
X_s = sorted(X)
Y_s = sorted(Y)

r = 10**20
for xi0 in range(N):
  for xi1 in range(xi0, N):
    for yi0 in range(N):
      for yi1 in range(yi0, N):
        x0 = X_s[xi0]
        x1 = X_s[xi1]
        y0 = Y_s[yi0]
        y1 = Y_s[yi1]
        c = 0
        for x, y in XY:
          if x0 <= x <=x1 and y0 <= y <= y1:
            c += 1
        if c >= K:
          r = min(r, (x1 - x0) * (y1 - y0))
print(r)