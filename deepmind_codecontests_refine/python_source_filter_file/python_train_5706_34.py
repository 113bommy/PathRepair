import sys,heapq
from collections import deque,defaultdict
printn = lambda x: sys.stdout.write(x)
inn = lambda : int(input())
inl   = lambda: list(map(int, input().split()))
inm   = lambda:      map(int, input().split())
DBG = True  and False
def ddprint(x):
  if DBG:
    print(x)

BIG = 10**12
n = inn()
rx = []
udx = []
lx = []
uy =[]
rly = []
dy = []
for i in range(n):
    x,y,d = input().split()
    x = int(x)
    y = int(y)
    if d=='R':
        rx.append(x)
        rly.append(y)
    elif d=='L':
        lx.append(x)
        rly.append(y)
    elif d=='U':
        udx.append(x)
        uy.append(y)
    elif d=='D':
        udx.append(x)
        dy.append(y)

nor = (len(rx)==0)
nol = (len(lx)==0)
nou = (len(uy)==0)
nod = (len(dy)==0)
noud = nou and nod
norl = nor and nol

if not nor:
    rx.sort()
    rmax  = rx[-1]
    rmin  = rx[0]
if not nol:
    lx.sort()
    lmax  = lx[-1]
    lmin  = lx[0]
if not nou:
    uy.sort()
    umax  = uy[-1]
    umin  = uy[0]
if not nod:
    dy.sort()
    dmax  = dy[-1]
    dmin  = dy[0]
if not noud:
    udx.sort()
    udmax  = udx[-1]
    udmin  = udx[0]
if not norl:
    rly.sort()
    rlmax  = rly[-1]
    rlmin  = rly[0]

ddprint(rx)
ddprint(udx)
ddprint(lx)
#ddprint("max: r {} l {} u {} d {}".format(rmax,lmax,umax,dmax))
#ddprint("min: r {} l {} u {} d {}".format(rmin,lmin,umin,dmin))

def foo(t):
    ddprint("foo t: {}".format(t))
    xmax = -BIG
    if not nor:
        xmax = max(xmax, rmax+t)
    if not noud:
        xmax = max(xmax, udmax)
    if not nol:
        xmax = max(xmax, lmax-t)
    xmin = BIG
    if not nor:
        xmin = min(xmin, rmin+t)
    if not noud:
        xmin = min(xmin, udmin)
    if not nol:
        xmin = min(xmin, lmin-t)

    ymax = -BIG
    if not nou:
        ymax = max(ymax, umax+t)
    if not norl:
        ymax = max(ymax, rlmax)
    if not nod:
        ymax = max(ymax, dmax-t)
    ymin = BIG
    if not nou:
        ymin = min(ymin, umin+t)
    if not norl:
        ymin = min(ymin, rlmin)
    if not nod:
        ymin = min(ymin, dmin-t)

    z = abs((xmax-xmin)*(ymax-ymin))
    ddprint("xmax {} xmin {} ymax {} ymin {} rtn {}".format(xmax,xmin,ymax,ymin,z))
    return z

ts = [0]
if not noud:
    if not nor:
        ts.append(max(0,udmax-rmax))
        ts.append(max(0,udmin-rmin))
    if not nol:
        ts.append(max(0,lmax-udmax))
        ts.append(max(0,lmin-udmin))
if not nol and not nor:
        ts.append(max(0,(lmax-rmax)/2))
        ts.append(max(0,(lmin-rmin)/2))
if not norl:
    if not nou:
        ts.append(max(0,rlmax-umax))
        ts.append(max(0,rlmin-umin))
    if not nod:
        ts.append(max(0,dmax-rlmax))
        ts.append(max(0,dmin-rlmin))
if not nod and not nou:
        ts.append(max(0,(dmax-umax)/2))
        ts.append(max(0,(dmin-umin)/2))

ts = list(set(ts))
mn = BIG
for t in ts:
    mn = min(mn, foo(t))
print(mn)
