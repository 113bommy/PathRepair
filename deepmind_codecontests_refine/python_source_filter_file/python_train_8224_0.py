import sys
class Line:
    def __init__(self,p1,p2):
        if p1[1] < p2[1]:self.s=p2;self.e=p1
        elif p1[1] > p2[1]:self.s=p1;self.e=p2
        else:
            if p1[0] < p2[0]:self.s=p1;self.e=p2
            else:self.s=p2;self.e=p1

def cross(a,b):return a[0]*b[1] - a[1]*b[0]
def dot(a,b):return a[0]*b[0]+a[1]*b[1]
def dif(a,b):return [x-y for x,y in zip(a,b)]
def dist(a,b):return ((a[0]-b[0])**2+(a[1]-b[1])**2)**0.5
def isec(l,m):
    a = dif(l.e,l.s);b = dif(m.e,l.s);c = dif(m.s,l.s)
    d = dif(m.e,m.s);e = dif(l.e,m.s);f = dif(l.s,m.s)
    g = lambda a, b : cross(a,b)==0 and dot(a,b)>0 and dot(b,b)<dot(a,a)
    if g(a,b) or g(a,c) or g(d,e) or g(d,f):return True
    elif l.s == m.e or l.s == m.s or l.e == m.e or l.e == m.s:return True
    elif cross(a,b) * cross(a,c) >= 0 or cross(d,e) * cross(d,f) >= 0:return False
    else:return True
def plus(a,b):return [x+y for x,y in zip(a,b)]
def projection(a,b):return [x*dot(a,b)/dot(a,a) for x in a]
def proj(A,B,C,D):
    AB = dif(B,A) ; AC = dif(C,A) ; AD = dif(D,A)
    CD = dif(D,C) ; CA = dif(A,C) ; CB = dif(B,C)
    _A = plus(projection(CD,CA),C) 
    _B = plus(projection(CD,CB),C)
    _C = plus(projection(AB,AC),A)
    _D = plus(projection(AB,AD),A)
    return [_A,_B,_C,_D]
def Order(a,b):
    crs = cross(a,b)
    if abs(crs) < 1.0e-11 : crs = 0.0
    if crs > 0 : return "COUNTER_CLOCKWISE"
    elif crs < 0 : return "CLOCKWISE"
    else:
        if dot(a,b) < 0 : return "ONLINE_BACK"
        elif dot(a,a) < dot(b,b) : return "ONLINE_FRONT"
        else : return "ON_SEGMENT"

q = int(input())
for i in range(q):
    a,b,c,d,e,f,g,h = [int(i) for i in input().split()]
    A = [a,b] ; B = [c,d] ; C = [e,f] ; D = [g,h]
    l = Line(A,B) ; m = Line(C,D)
    if isec(l,m):
        print(0.0)
        continue
    _A,_B,_C,_D = proj(A,B,C,D)
    AB = dif(B,A) ; CD = dif(D,C)
    A_C = dif(_C,A) ; A_D = dif(_D,A) ; C_A = dif(_A,C) ; C_B = dif(_B,C)
    DIST = [dist(A,C),dist(A,D),dist(B,C),dist(B,D),dist(_A,A),dist(_B,B),dist(_C,C),dist(_D,D)]
    fun = lambda x : x != "ON_SEGMENT"
    if fun(Order(CD,C_A)) : DIST[4] = sys.maxsize
    if fun(Order(CD,C_B)) : DIST[5] = sys.maxsize
    if fun(Order(AB,A_C)) : DIST[6] = sys.maxsize
    if fun(Order(AB,A_D)) : DIST[7] = sys.maxsize
    print(min(DIST))