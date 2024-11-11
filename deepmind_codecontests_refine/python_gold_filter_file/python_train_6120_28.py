from math import sqrt, fabs


class Circle:
    def __init__(self, x, y, r):
        self.x = x
        self.y = y
        self.r = r
        self.eps = 1e-8

    def contain(self, x, y):
        d2 = (self.x - x) ** 2 + (self.y - y) ** 2
        return d2 <= self.r ** 2 + self.eps

    def intersect(self, other):
        eps = self.eps

        if self.r > other.r:
            x1, y1, R = self.x, self.y, self.r
            x2, y2, r = other.x, other.y, other.r
        else:
            x1, y1, R = other.x, other.y, other.r
            x2, y2, r = self.x, self.y, self.r
        d = sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)

        # d = 0 and R = r
        if fabs(d) < eps and fabs(R - r) < eps:
            return '相同', None

        # d == R - r
        if fabs(d - (R - r)) < eps:
            x3 = (R * x2 - r * x1) / (R - r)
            y3 = (R * y2 - r * y1) / (R - r)
            return '內切', [(x3, y3)]

        # d == R + r
        if fabs(d - (R + r)) < eps:
            x3 = (R * x1 + r * x2) / (R + r)
            y3 = (R * y1 + r * y2) / (R + r)
            return '外切', [(x3, y3)]

        # d < R - r
        if d < R - r + eps:
            return '內離', None

        # d > R + R
        if d > R + r + eps:
            return '外離', None

        # R - r < d < R + r
        a = (R ** 2 - r ** 2 + d ** 2) / (2 * d)
        h = sqrt(R ** 2 - a ** 2)
        cx = x1 + a * (x2 - x1) / d
        cy = y1 + a * (y2 - y1) / d
        x3 = cx + h * (y2 - y1) / d
        y3 = cy - h * (x2 - x1) / d
        x4 = cx - h * (y2 - y1) / d
        y4 = cy + h * (x2 - x1) / d
        return '相交', [(x3, y3), (x4, y4)]


N, K = map(int, input().split())
X, Y, C = [], [], []
for _ in range(N):
    x, y, c = map(int, input().split())
    X.append(x)
    Y.append(y)
    C.append(c)


def check(t):
    circles = [Circle(x, y, t / c) for x, y, c in zip(X, Y, C)]

    cands = []
    for i in range(N):
        cands.append((X[i], Y[i]))
        for j in range(i + 1, N):
            kind, points = circles[i].intersect(circles[j])
            if kind in ['相交', '內切', '外切']:
                cands.extend(points)

    for (x, y) in cands:
        cnt = sum(1 for circle in circles if circle.contain(x, y))
        if cnt >= K:
            return True

    return False


# 0 0 0 1 1 1
lb, ub = 0, 1e9
for _ in range(100):
    mid = (lb + ub) / 2
    if check(mid):
        ub = mid
    else:
        lb = mid
print(ub)
