import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**20
eps = 1.0 / 10**13
mod = 10**9+7
dd = [(-1,0),(0,1),(1,0),(0,-1)]
ddn = [(-1,0),(-1,1),(0,1),(1,1),(1,0),(1,-1),(0,-1),(-1,-1)]

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()
def pf(s): return print(s, flush=True)

def area(xy):
    xy = sorted(xy)
    x = [xy[i][0] - xy[0][0] for i in range(3)]
    y = [xy[i][1] - xy[0][1] for i in range(3)]
    return abs(x[1]*y[2] - x[2]*y[1]) / 2

def ccw(a, b, c):
    ax = b[0] - a[0]
    ay = b[1] - a[1]
    bx = c[0] - a[0]
    by = c[1] - a[1]
    t = ax*by - ay*bx;
    if t > 0:
        return 1
    if t < 0:
        return -1
    if ax*bx + ay*by < 0:
        return 2
    if ax*ax + ay*ay < bx*bx + by*by:
        return -2
    return 0

def convex_hull(ps):
    n = len(ps)
    k = 0
    ps.sort()
    ch = [None] * (n*2)
    for i in range(n):
        while k >= 2 and ccw(ch[k-2], ch[k-1], ps[i]) <= 0:
            k -= 1
        ch[k] = ps[i]
        k += 1
    t = k + 1
    for i in range(n-2,-1,-1):
        while k >= t and ccw(ch[k-2], ch[k-1], ps[i]) <= 0:
            k -= 1
        ch[k] = ps[i]
        k += 1

    return ch[:k-1]

def bs(f, mi, ma):
    mm = -1
    while ma > mi + eps:
        mm = (ma+mi) / 2.0
        if f(mm):
            mi = mm + eps
        else:
            ma = mm
    if f(mm):
        return mm + eps
    return mm

def intersection(a1, a2, b1, b2):
    x1,y1 = a1
    x2,y2 = a2
    x3,y3 = b1
    x4,y4 = b2

    ksi = (y4 - y3) * (x4 - x1) - (x4 - x3) * (y4 - y1)
    eta = (x2 - x1) * (y4 - y1) - (y2 - y1) * (x4 - x1)
    delta = (x2 - x1) * (y4 - y3) - (y2 - y1) * (x4 - x3)
    if delta == 0:
        return None
    ramda = ksi / delta;
    mu = eta / delta;
    if ramda >= 0 and ramda <= 1 and mu >= 0 and mu <= 1:
        return (x1 + ramda * (x2 - x1), y1 + ramda * (y2 - y1))

    return None

def main():
    n = I()
    a = convex_hull([LI() for _ in range(n)])
    n = len(a)
    a = a + a + a
    s = 0
    for i in range(1,n-1):
        s += area([a[0],a[i],a[i+1]])
    def f(i, fk):
        t = 0
        tj = i + 1
        ra = [a[i+1][j] - a[i][j] for j in range(2)]
        ap = [a[i][j] + ra[j] * fk for j in range(2)]
        for j in range(i+1, i+n):
            u = area([ap, a[j], a[j+1]])
            if t + u >= s / 2:
                tj = j
                break
            t += u
        ts = s / 2 - t
        sa = [a[tj+1][j] - a[tj][j] for j in range(2)]
        def _f(k):
            b = [a[tj][j] + sa[j] * k for j in range(2)]
            fs = area([a[i], a[tj], b])
            return fs < ts
        bk = bs(_f, 0, 1)
        return [ap, [a[tj][j] + sa[j] * bk for j in range(2)]]

    ls = [f(i//5, random.random()) for i in range(n*5)]
    ll = len(ls)
    kts = []
    sx = 0
    sy = 0
    for i in range(ll):
        for j in range(i+1,ll):
            t = intersection(ls[i][0], ls[i][1], ls[j][0], ls[j][1])
            if t is None:
                return 'NA'
            kts.append(t)
            sx += t[0]
            sy += t[1]
    mx = sx / len(kts)
    my = sy / len(kts)
    keps = 1.0 / 10**5
    for i in range(len(kts)):
        if abs(mx-t[0]) > keps or abs(my-t[1]) > keps:
            return 'NA'
    return '{} {}'.format(mx, my)



print(main())

