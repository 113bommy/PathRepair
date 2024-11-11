def dist(x, y, xx, yy):
    return abs(x - xx) + abs(y - yy)

x0, y0, ax, ay, bx, by = map(int, input().split())
xs, ys, t = map(int, input().split())
x = []
y = []
x += [x0]
y += [y0]
while x0 < 1e3 and y0 < 1e3:
    xi = ax * x0 + bx
    yi = ay * y0 + by
    x += [xi]
    y += [yi]
    x0 = xi
    y0 = yi
mx = 0
for i in range(len(x)):
    d = dist(x[i], y[i], xs, ys)
    if t < d:
        continue
    else:
        mx = max(mx, 1)
    for j in range(i + 1, len(x)):
        if t - d - dist(x[j], y[j], x[i], y[i]) >= 0:
            mx = max(mx, j - i + 1)
    for j in range(i - 1, -1, -1):
        if t - d - dist(x[j], y[j], x[i], y[i]) >= 0:
            mx = max(mx, i - j + 1)
print(mx)