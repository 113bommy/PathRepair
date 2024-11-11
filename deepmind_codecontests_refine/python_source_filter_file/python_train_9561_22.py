N, K = map(int, input().split())
XY = [[0, 0, 0] for _ in range(N)]
for i in range(N):
  x, y = map(int, input().split())
  XY[i] = [x, y, i]
X = sorted(XY)
Y = sorted(XY, key=lambda x: x[1])
rect = (X[-1][0] - X[0][0]) * (Y[-1][1] - Y[0][1])
for l in range(N - K + 1):
  for r in range(l + K - 1, N):
    for d in range(N - K + 1):
      for u in range(d + K - 1, N - 1):
        if len([x for x in XY if X[l][0] <= x[0] <= X[r][0] and Y[d][1] <= x[1] <= Y[u][1]]) >= K:
          rect = min((X[r][0] - X[l][0]) * (Y[u][1] - Y[d][1]), rect)
print(rect)