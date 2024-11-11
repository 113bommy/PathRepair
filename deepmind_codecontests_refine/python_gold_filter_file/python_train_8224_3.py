from sys import stdin
import math

EPS = 1e-10

class Vector:
    def __init__(self, x=None, y=None):
        self.x = x
        self.y = y

    def __add__(self, other):
        return Vector(self.x + other.x, self.y + other.y)

    def __sub__(self, other):
        return Vector(self.x - other.x, self.y - other.y)

    def __mul__(self, k):
        return Vector(self.x * k, self.y * k)

    def __gt__(self, other):
        return self.x > other.x and self.y > other.yb

    def __lt__(self, other):
        return self.x < other.x and self.y < other.yb

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y

    def dot(self, other):
        return self.x * other.x + self.y * other.y

    # usually cross operation return Vector but it returns scalor
    def cross(self, other):
        return self.x * other.y - self.y * other.x

    def norm(self):
        return self.x * self.x + self.y * self.y

    def abs(self):
        return math.sqrt(self.norm())

class Point(Vector):
    def __init__(self, *args, **kargs):
        return super().__init__(*args, **kargs)

class Segment:
    def __init__(self, p1=Point(0, 0), p2=Point(1, 1)):
        self.p1 = p1
        self.p2 = p2

def ccw(p0, p1, p2):
    a = p1 - p0
    b = p2 - p0
    if a.cross(b) > EPS:
        return 1
    elif a.cross(b) < -EPS:
        return -1
    elif a.dot(b) < -EPS:
        return 2
    elif a.norm() < b.norm():
        return -2
    else:
        return 0

def intersect(*args, **kwargs):
    # input two segments
    if len(args) == 2:
        s1, s2 = args
        return (ccw(s1.p1, s1.p2, s2.p1) * ccw(s1.p1, s1.p2, s2.p2) <= 0 and
                    ccw(s2.p1, s2.p2, s1.p1) * ccw(s2.p1, s2.p2, s1.p2) <= 0)
    # input four points
    elif len(args) == 4:
        p0, p1, p2, p3 = args
        return (ccw(p0, p1, p2) * ccw(p0, p1, p3) <= 0 and
                    ccw(p2, p3, p0) * ccw(p2, p3, p1) <= 0)
    else:
        raise ArgsError

def get_distance_lp(l, p):
    v1 = l.p1 - l.p2
    v2 = p - l.p1
    return abs(v1.cross(v2))/v1.abs()

def get_distance_sp(s, p):
    v1 = s.p2 - s.p1
    v2 = p - s.p1
    v3 = s.p1 - s.p2
    v4 = p - s.p2
    if v1.dot(v2) < 0:
        return v2.abs()
    elif v3.dot(v4) < 0:
        return v4.abs()
    else:
        return get_distance_lp(s, p)

def get_distance(*args, **kwargs):
    # input two points with the startpoint (0, 0)
    if len(args) == 2:
        p1, p2 = args
        v = p1 - p2
        return v.abs()
    # input two segments
    elif len(kwargs) == 2:
        s1 = kwargs['s1']
        s2 = kwargs['s2']
        if intersect(s1, s2):
            return 0.0
        else:
            return min(min(get_distance_sp(s1, s2.p1), get_distance_sp(s1, s2.p2)),
                        min(get_distance_sp(s2, s1.p1), get_distance_sp(s2, s1.p2)))
    else:
        raise ArgsError

def read_and_print_results(n):
    for _ in range(n):
        line = stdin.readline().strip().split()
        p0 = Vector(int(line[0]), int(line[1]))
        p1 = Vector(int(line[2]), int(line[3]))
        p2 = Vector(int(line[4]), int(line[5]))
        p3 = Vector(int(line[6]), int(line[7]))
        s1 = Segment(p0, p1)
        s2 = Segment(p2, p3)
        d = get_distance(s1=s1, s2=s2)
        print("{0:0.10f}".format(d))

n = int(input())
read_and_print_results(n)
