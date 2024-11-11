# -*- coding: utf-8 -*-
"""
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B&lang=jp

"""
import sys
from sys import stdin
input = stdin.readline


class Point(object):
    epsilon = 1e-10

    def __init__(self, x=0.0, y=0.0):
        if isinstance(x, tuple):
            self.x = x[0]
            self.y = x[1]
        else:
            self.x = x
            self.y = y

    # ????????????
    def __add__(self, other):
        return Point(self.x + other.x, self.y + other.y)

    def __sub__(self, other):
        return Point(self.x - other.x, self.y - other.y)

    def __mul__(self, other):
        return Point(other * self.x, other * self.y)

    def __truediv__(self, other):
        return Point(other / self.x, other / self.y)

    def __lt__(self, other):
        if self.x == other.x:
            return self.y < other.y
        else:
            return self.x < other.x

    def __eq__(self, other):
        from math import fabs
        if fabs(self.x - other.x) < Point.epsilon and fabs(self.y - other.y) < Point.epsilon:
            return True
        else:
            return False

    def norm(self):
        return self.x * self.x + self.y * self.y

    def abs(self):
        from math import sqrt
        return sqrt(self.norm())


class Vector(Point):
    def __init__(self, x=0.0, y=0.0):
        if isinstance(x, tuple):
            self.x = x[0]
            self.y = x[1]
        elif isinstance(x, Point):
            self.x = x.x
            self.y = x.y
        else:
            self.x = x
            self.y = y

    # ????????????
    def __add__(self, other):
        return Vector(self.x + other.x, self.y + other.y)

    def __sub__(self, other):
        return Vector(self.x - other.x, self.y - other.y)

    def __mul__(self, other):
        return Vector(other * self.x, other * self.y)

    def __truediv__(self, other):
        return Vector(other / self.x, other / self.y)

    @classmethod
    def dot(cls, a, b):
        return a.x * b.x + a.y * b.y

    @classmethod
    def cross(cls, a, b):
        return a.x * b.y - a.y * b.x

    @classmethod
    def is_orthogonal(cls, a, b):
        return Vector.dot(a, b) == 0.0

    @classmethod
    def is_parallel(cls, a, b):
        return Vector.cross(a, b) == 0.0


class Segment(object):
    def __init__(self, p1=Point(), p2=Point()):
        if isinstance(p1, Point):
            self.p1 = p1
            self.p2 = p2
        elif isinstance(p1, tuple):
            self.p1 = Point(p1[0], p1[1])
            self.p2 = Point(p2[0], p2[1])

    @classmethod
    def is_orthogonal(cls, s1, s2):
        a = Vector(s1.p2 - s1.p1)
        b = Vector(s2.p2 - s2.p1)
        return Vector.is_orthogonal(a, b)

    @classmethod
    def is_parallel(cls, s1, s2):
        a = Vector(s1.p2 - s1.p1)
        b = Vector(s2.p2 - s2.p1)
        return Vector.is_parallel(a, b)


class Line(Segment):
    pass


class Cirle(object):
    def __init__(self, c=Point(), r=0.0):
        self.c = c
        self.r = r


def ccw(p0, p1, p2):
    a = Vector(p1 - p0)
    b = Vector(p2 - p0)
    epsilon = 1e-10
    if Vector.cross(a, b) > epsilon:
        return 1 # 'COUNTER_CLOCKWISE'
    elif Vector.cross(a, b) < -epsilon:
        return -1 # 'CLOCKWISE'
    elif Vector.dot(a, b) < -epsilon:
        return 1 # 'ONLINE_BACK'
    elif a.norm() < b.norm():
        return 1 # 'ONLINE_FRONT'
    else:
        return 0 # 'ON_SEGMENT'


def intersect(p0, p1, p2, p3):
    ans1 = ccw(p0, p1, p2) * ccw(p0, p1, p3)
    ans2 = ccw(p2, p3, p0) * ccw(p2, p3, p1)
    return ans1 <= 0 and ans2 <= 0


def main(args):
    q = int(input())
    for _ in range(q):
        x_p0, y_p0, x_p1, y_p1, x_p2, y_p2, x_p3, y_p3 = map(int, input().split())
        p0 = Point(x_p0, y_p0)
        p1 = Point(x_p1, y_p1)
        p2 = Point(x_p2, y_p2)
        p3 = Point(x_p3, y_p3)
        result = intersect(p0, p1, p2, p3)
        print(int(result))


if __name__ == '__main__':
    main(sys.argv[1:])