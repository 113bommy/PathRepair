from math import sqrt


class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y


class Vector:
    def __init__(self, x1, y1, x2, y2):
        self.x1 = x1
        self.y1 = y1
        self.x2 = x2
        self.y2 = y2

    def count(self):
        return sqrt((self.x2 - self.x1) ** 2 + (self.y2 - self.y1) ** 2)


class Square:
    def __init__(self, x1, y1, x2, y2, x3, y3, x4, y4):
        self.x1 = x1
        self.x2 = x2
        self.x3 = x3
        self.x4 = x4
        self.y1 = y1
        self.y2 = y2
        self.y3 = y3
        self.y4 = y4

    def space(self):
        return Vector(self.x1, self.y1, self.x2, self.y2).count() * Vector(self.x2, self.y2, self.x3, self.y3).count()


class Triangle:
    def __init__(self, x1, y1, x2, y2, x3, y3):
        self.x1 = x1
        self.x2 = x2
        self.x3 = x3
        self.y1 = y1
        self.y2 = y2
        self.y3 = y3

    def space(self):
        v1 = Vector(self.x1, self.y1, self.x2, self.y2).count()
        v2 = Vector(self.x1, self.y1, self.x3, self.y3).count()
        v3 = Vector(self.x2, self.y2, self.x3, self.y3).count()
        p = (v1 + v2 + v3) / 2
        v1 = round(v1, 8)
        v2 = round(v2, 8)
        v3 = round(v3, 8)
        p = round(p, 8)
        return sqrt(p * (p - v1) * (p - v2) * (p - v3))


n, d = map(int, input().split())
amount = int(input())
req = []
for i in range(amount):
    x, y = map(int, input().split())
    req.append(Point(x, y))

sq = Square(0, d, n - d, n, n, n - d, d, 0)
S = sq.space()

EPS = 0.0001
for elem in req:
    space1 = Triangle(elem.x, elem.y, 0, d, n - d, n).space()
    space2 = Triangle(elem.x, elem.y, n - d, n, n, n - d).space()
    space3 = Triangle(elem.x, elem.y, n, n - d, d, 0).space()
    space4 = Triangle(elem.x, elem.y, d, 0, 0, d).space()
    if abs(space1 + space2 + space3 + space4 - S) <= EPS:
        print('YES')
    else:
        print('NO')
