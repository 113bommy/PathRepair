N, K = map(int, input().split())
xys = []
for i in range(N):
  x, y = map(int, input().split())
  xys.append((x, y))
xs = sorted(map(lambda xy: xy[0], xys))
ys = sorted(map(lambda xy: xy[1], xys))
rs = []
for i in range(N):
  for j in range(i+1, N):
    x1 = xs[i]
    x2 = xs[j]
    for k in range(N):
      for l in range(k+1, N):
        y1 = ys[i]
        y2 = ys[j]
        n = len([(x, y) for x, y in xys if x1 <= x <= x2 and y1 <= y <= y2])
        #xys2 = filter(lambda xy: x1 <= xy[0] <= x2 and y1 <= xy[1] <= y2, xys)
        if n >= K:
          r = (x2-x1)*(y2-y1)
          rs.append(r)
r = min(rs)
print(r)
