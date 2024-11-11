from math import hypot
N, K = map(int, input().split())
def count(x, y, T, cs):
    r = 0
    for a, b, c in cs:
        r += int(hypot(x-a, y-b) <= T/c + 10**-8)
#    print(x, y, r)
    return r

def ko(x1, y1, r1, r2):
    # x^2+y^2=r1, (x-x1)^2+(y-y1)^2=r2
    a = (x1**2 + y1**2 + r1**2 - r2**2)/2

    t = (x1**2+y1**2)*r1**2-a**2
    if t < 0:
        return -1

    x = a*x1
    xb = y1*t**(1/2)
    y = a*y1
    yb = x1*t**(1/2)
    b = x1**2+y1**2
    return ((x+xb)/b, (y-yb)/b), ((x-xb)/b, (y+yb)/b)

def zko(x1, y1, r1, x2, y2, r2):
    r = ko(x2-x1, y2-y1, r1, r2)
    if r == -1:
        return -1
    (xp, yp), (xm, ym) = ko(x2-x1, y2-y1, r1, r2)
    return (xp+x1, yp+y1), (xm+x1, ym+y1)

def f(T, cs):
    ccs = []
    for i in range(N):
        (xi, yi, ci) = cs[i]
        for j in range(i+1, N):
            (xj, yj, cj) = cs[j]
            r = zko(xi, yi, T/ci, xj, yj, T/cj)
#            r =  gm.get_cross_pointCC((xi, yi, T/ci), (xj, yj, T/cj))
            if r == -1:
                continue
            (x1, y1), (x2, y2) = r
#            print(x1, y1, x2, y2)
            ccs.append((x1, y1))
            ccs.append((x2, y2))
    for a, b, c in cs:
        ccs.append((a, b))
#    print(ccs)
    for x, y in ccs:
        if count(x, y, T, cs) >= K:
            return True
    return False

#print(ko(0, 1, 1, 1))
#print(zko(1, 0, 1, 1, 1, 1))
#print(zko(0,1,5,4,3,5**0.5))
cs = []
for i in range(N):
    x, y, c = map(int, input().split())
    cs.append((x, y, c))
mx, mn = 10**5, -1
idx = mx/2
for _ in range(100):
    if f(idx, cs):
        idx, mx = (idx+mn)/2, idx
        continue
    idx, mn = (idx+mx)/2, idx
print(idx)

#print(f(2.97, cs))
#
#for i in range(741100,741200):
#    j = i * 100
#    j = i/100
#    print(j, f(j, cs))

#print(f(10411.3, cs))
#for i in range(N):
#    (xi, yi, ci) = cs[i]
#    for j in range(i+1, N):
#        (xj, yj, cj) = cs[j]
