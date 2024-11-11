from sys import stdin
readline = stdin.readline


def cross(a, b):
    return a.real * b.imag - a.imag * b.real


def dot(a, b):
    return a.real * b.real + a.imag * b.imag


def eq(a, b):
    return abs(a - b) < 1e-10


def on_line(p, s, e):
    d = dot(p - s, e - s)
    c = cross(p - s, e - s)
    if c == 0 and 0 <= d <= abs(e - s) ** 2:
        return True
    return False


def on_polygon_line(xy, p):
    for i in range(len(p)):
        j = i - 1
        if on_line(xy, p[i], p[j]):
            return True
    return False


def in_polygon(xy, p):
    wn = 0
    for i in range(len(p)):
        j = i - 1
        if 0 == (p[i] - p[j]).imag:
            continue
        vt = (xy - p[j]).imag / (p[i] - p[j]).imag
        tmp = p[j] + vt * (p[i] - p[j])
        if xy.real < tmp.real:
            wn += 1 if p[j].imag <= xy.imag < p[i].imag else\
                 -1 if p[i].imag <= xy.imag < p[j].imag else 0
    return wn

n = int(readline())
p = [map(int, readline().split()) for _ in range(n)]
p = [x + y * 1j for x, y in p]

q = int(readline())
for _ in range(q):
    x, y = map(int, readline().split())
    xy = x + y * 1j
    print(1 if on_polygon_line(xy, p) else 2 if in_polygon(xy, p) else 0)