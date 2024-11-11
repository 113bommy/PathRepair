from math import sqrt
q = int(input())

class Segment(): pass

def dot(a, b):
    return sum([i * j for i,j in zip(a, b)])

def sub(a, b):
    return [a[0] - b[0],a[1] - b[1]]

def cross(a, b):
    return  a[0] * b[1] - a[1] * b[0]

def norm(a):
    return sqrt(a[0] ** 2 + a[1] ** 2)

def ccw(a, b, c):
    x = sub(b, a)
    y = sub(c, a)
    if cross(x, y) > 0: return 1
    if cross(x, y) < 0: return -1
    if dot(x, y) < 0: return 2
    if norm(x) < norm(y): return -2
    return 0

def intersect(p1, p2, p3, p4):
    return ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 and \
           ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0

def getDistLP(s, p):
    return abs(cross(sub(s.r, s.l), sub(p, s.l))) / norm(sub(s.r, s.l))

def getDistSP(s, p):
    if dot(sub(s.r, s.l),sub(p, s.l)) < 0: return norm(sub(p, s.l))
    if dot(sub(s.l, s.r),sub(p, s.r)) < 0: return norm(sub(p, s.r))
    return getDistLP(s, p)

def getDist(s1, s2):
    if intersect(s1.l, s1.r, s2.l, s2.r): return 0
    return min(getDistSP(s1, s2.l), 
               getDistSP(s1, s2.r),
               getDistSP(s2, s1.l),
               getDistSP(s2, s1.r))

for i in range(q):
    xp0, yp0, xp1, yp1, xp2, yp2, xp3, yp3  = map(int, input().split())
    s1 = Segment()
    s2 = Segment()
    s1.l = [xp0, yp0]
    s1.r = [xp1, yp1]
    s2.l = [xp2, yp2]
    s2.r = [xp3, yp3]
    print(getDist(s1, s2))