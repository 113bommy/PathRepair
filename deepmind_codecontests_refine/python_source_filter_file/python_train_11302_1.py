from sys import stdin

n = int(stdin.readline())
x, y = map(int, stdin.readline().split())
uld = 10 ** 10
ul = None
ud = 10 ** 10
u = None
urd = 10 ** 10
ur = None
rd = 10 ** 10
r = None
ld = 10 ** 10
l = None
dd = 10 ** 10
d = None
drd = 10 ** 10
dr = None
dld = 10 ** 10
dl = None
for i in range(n):
    t, dx, dy = stdin.readline().split()
    dx = int(dx)
    dy = int(dy)
    if dx == x:
        if dy > y:
            if ud > dy - y:
                ud = dy - y
                u = t
        else:
            if dd > y - dy:
                dd = y - dy
                d = t
    if dy == y:
        if dx > x:
            if rd > dx - x:
                rd = dx - x
                r = t
        else:
            if ld > x - dx:
                ld = dx - x
                l = t
    if dx - x == dy - y:
        if dy > y:
            if urd > dy - y:
                urd = dy - y
                ur = t
        else:
            if dld > y - dy:
                dld = y - dy
                dl = t
    if -(dx - x) == dy - y:
        if dy > y:
            if uld > dy - y:
                uld = dy - y
                ul = t
        else:
            if drd > y - dy:
                drd = y - dy
                dr = t

if 'B' in (ul, ur, dl, dr) or 'R' in (u, d, l, r) or 'Q' in (ul, ur, dl, dr, u, d, l, r):
    print('YES')
else:
    print('NO')