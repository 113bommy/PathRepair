from math import sqrt
ax, ay, bx, by, cx, cy = tuple(map(int, input().split()))

def hypot(x1, y1, x2, y2):
    return sqrt((x1-x2)**2 + (y1-y2)**2)

def pend(x1, x2, y1, y2):
    if x1-x2 == 0: return 10**20
    return (y1-y2)/(x1- x2)

if hypot(ax, ay, bx, by) == hypot(cx, cy, bx, by):
    if pend(ax, bx, ay, by) == pend(cx, bx, cy, by): print('No')
    else: print('Yes')
else: print('No')