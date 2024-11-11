N = int(input())
xy = [list(map(int, input().split())) for _ in range(N)]
def nasu(a, b, c):
  A = a[0] ** 2 - b[0] ** 2 + a[1] ** 2 - b[1] ** 2
  B = b[0] ** 2 - c[0] ** 2 + b[1] ** 2 - c[1] ** 2
  x = [2 * (b[0] - a[0]), 2 * (c[0] - b[0])]
  y = [2 * (b[1] - a[1]), 2 * (c[1] - b[1])]
  k = x[1] * y[0] - x[0] * y[1]
  if k == 0:
    return 10 ** 10
  Cx = (x[0] * B - x[1] * A) / k
  Cy = -(y[0] * B - y[1] * A) / k
  return honyamorake(Cx, Cy)

def honya(x, y, Cx, Cy):
  return ((x - Cx) ** 2 + (y - Cy) ** 2) ** (1 / 2)

def honyaraka(a, b):
  Cx = (a[0] + b[0]) / 2
  Cy = (a[1] + b[1]) / 2
  return honyamorake(Cx, Cy)

def honyamorake(Cx, Cy):
  r = honya(xy[0][0], xy[0][1], Cx, Cy)
  for i in range(1, N):
    r = max(r, honya(xy[i][0], xy[i][1], Cx, Cy))
  return r

ans = 10 ** 10
for i in range(N - 2):
  for j in range(i + 1, N - 1):
    for k in range(j + 1, N):
      ans = min(ans, nasu(xy[i], xy[j], xy[k]))
for i in range(N - 1):
  for j in range(i + 1, N):
    ans = min(ans, honyaraka(xy[i], xy[j]))

print(ans)