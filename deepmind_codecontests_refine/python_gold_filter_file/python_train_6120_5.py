import sys

sys.setrecursionlimit(10 ** 6)
int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")
def II(): return int(sys.stdin.readline())
def MI(): return map(int, sys.stdin.readline().split())
def LI(): return list(map(int, sys.stdin.readline().split()))
def LLI(rows_number): return [LI() for _ in range(rows_number)]
def SI(): return sys.stdin.readline()[:-1]

class Vector:
    def __init__(self, x, y):
        self.x, self.y = x, y
        self.sqrnorm = pow(self.x, 2) + pow(self.y, 2)
        self.norm = self.sqrnorm ** 0.5

    def __add__(self, other):
        return Vector(self.x + other.x, self.y + other.y)

    def __sub__(self, other):
        return Vector(self.x - other.x, self.y - other.y)

    def __mul__(self, other):
        return Vector(self.x * other, self.y * other)

    __rmul__ = __mul__

class Circle:
    def __init__(self, ox, oy, r):
        self.o, self.r = Vector(ox, oy), r

def rot90(v): return Vector(-v.y, v.x)

def comv(c1, c2):
    if c1.r < c2.r: c1, c2 = c2, c1
    r1, o1 = c1.r, c1.o
    r2, o2 = c2.r, c2.o
    d = (o1 - o2).norm
    s, mx = r1 + r2 + d, max(r1, r2, d)
    if s + eps < 2 * mx: return []
    elif s > 2 * mx:
        a = (r1 * r1 - r2 * r2 + d * d) / d / 2
        h = (r1 * r1 - a * a) ** 0.5
        o2o1 = o2 - o1
        v1 = o1 + o2o1 * (a / d) + rot90(o2o1) * (h / d)
        v2 = o1 + o2o1 * (a / d) - rot90(o2o1) * (h / d)
        return [v1, v2]
    else: return [(o2 - o1) * (r1 / d)]

def isinside(c, v): return (c.o - v).norm <= c.r + eps

eps = 10 ** -7
def main():
    def ok(t):
        # 円の列挙と中心の列挙
        cc = []
        vv = []
        for x, y, c in xyc:
            cc.append(Circle(x, y, t / c))
            vv.append(Vector(x, y))
        # 共有点の列挙
        for j in range(n):
            for i in range(j):
                vv += comv(cc[i], cc[j])
        for v in vv:
            cnt=0
            for c in cc:
                if isinside(c,v):cnt+=1
                if cnt==k:return True
        return False

    n, k = MI()
    xyc = LLI(n)
    l, r = 0, 200000
    for _ in range(50):
        t = (l + r) / 2
        if ok(t): r = t
        else: l = t
    print(t)

main()
