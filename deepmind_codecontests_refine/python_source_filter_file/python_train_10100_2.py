from math import sqrt
cx,cy,r = map(int,input().split())
c = [cx, cy]
q = int(input())

class Line:pass

def dot(a, b):
    return sum([i * j for i,j in zip(a, b)])
def add(a,b):
    return [a[0] + b[0],a[1] + b[1]]
def sub(a, b):
    return [a[0] - b[0],a[1] - b[1]]
def multi(k, a):
    return [k*a[0],k*a[1]]
def cross(a, b):
    return  a[0] * b[1] - a[1] * b[0]
def norm(a):
    return sqrt(a[0] ** 2 + a[1] ** 2)    
def proj(p, l):
    base = sub(l.p2, l.p1)
    hypo = sub(p, l.p1)
    t = dot(hypo,base) / norm(base)
    return add(l.p1, multi(t/norm(base), base))
    
for i in range(q):
    x1,y1,x2,y2 = map(int, input().split())
    l = Line()
    l.p1 = [x1,y1]
    l.p2 = [x2,y2]
    pr = proj(c, l)
    e = multi(1/norm(sub(l.p2, l.p1)),sub(l.p2, l.p1))
    e2 = multi(-1, e)
    base = sqrt(r**2 - norm(sub(pr,c))**2)
    a = add(pr, multi(base, e))
    b = add(pr, multi(base, e2))
    ans = [a,b]
    ans = sorted(ans, key=lambda x: (x[0],x[1]))
    print(' '.join([str(i) for o in ans for i in o]))