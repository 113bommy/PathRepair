def recKF(p1,p2,n):
    if n != 0:
        a = 1/2
        b = 3**(1/2)/2
        s = Point( p1.x + (p2.x-p1.x)/3, p1.y + (p2.y-p1.y)/3 )
        t = Point( p1.x + (p2.x-p1.x)*2/3, p1.y + (p2.y-p1.y)*2/3 )
        v = Point( t.x-s.x, t.y-s.y )
        rot_v = Point( v.x*a - v.y*b, b*v.x + a*v.y )
        u = Point( rot_v.x + s.x, rot_v.y + s.y)
        recKF(p1,s,n-1)
        print(s.x,s.y)
        recKF(s,u,n-1)
        print(u.x,u.y)
        recKF(u,t,n-1)
        print(t.x,t.y)
        recKF(t,p2,n-1)
        
from collections import namedtuple
Point = namedtuple("Point", ["x","y"])
p1 = Point(0,0)
p2 = Point(100,0)
n = int(input())
print(p1.x,p1.y)
recKF(p1,p2,n)
print(p2.x,p2.y)
