f = lambda: map(int, input().split())
a, b, c, d = f()
s, t = f()
vx, vy = f()
ux, uy = f()
def g(m):
    vt = min(t, m)
    ut = max(0, m - t)
    x = c - a - ut * ux - vt * vx
    y = d - b - ut * uy - vt * vy
    return x * x + y * y > (m * s) ** 2
l, r = 0, 1e9
while r - l > 1e-6:
    m = (l + r) / 2
    if g(m): l = m
    else: r = m
print(r)