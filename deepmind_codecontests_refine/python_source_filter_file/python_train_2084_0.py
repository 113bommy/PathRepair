class Point:
    def __init__(self, x , y):
        self.x = x
        self.y = y
    def __sub__(self, p):
        x_sub = self.x - p.x
        y_sub = self.y - p.y
        return Point(x_sub, y_sub)

class Vector:
    def __init__(self, p):
        self.x = p.x
        self.y = p.y
    def norm(self):
        return (self.x ** 2 + self.y ** 2) ** 0.5

def cross(v1, v2):
    return v1.x * v2.y - v1.y * v2.x

def dot(v1, v2):
    return v1.x * v2.x + v1.x * v2.x

def ccw(p0, p1, p2):
    a = Vector(p1 - p0)
    b = Vector(p2 - p0)
    cross_ab = cross(a, b)
    if cross_ab > 0:
        print("COUNTER_CLOCKWISE")
    elif cross_ab < 0:
        print("CLOCKWISE")
    elif dot(a, b) < 0:
        print("ONLINE_BACK")
    elif a.norm() < b.norm():
        print("ONLINE_FRONT")
    else:
        print("ON_SEGMENT")

import sys

file_input = sys.stdin

x_p0, y_p0, x_p1, y_p1 = map(int, file_input.readline().split())
p0 = Point(x_p0, y_p0)
p1 = Point(x_p1, y_p1)

q = map(int, file_input.readline())

for line in file_input:
    x_p2, y_p2 = map(int, line.split())
    p2 = Point(x_p2, y_p2)
    ccw(p0, p1, p2)