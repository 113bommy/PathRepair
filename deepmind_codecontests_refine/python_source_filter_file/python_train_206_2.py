# Aizu Problem CGL_3_B: Is-Convex
#
import sys, math, os

# read input:
PYDEV = os.environ.get('PYDEV')
if PYDEV=="True":
    sys.stdin = open("sample-input.txt", "rt")


def is_convex(P):
    # check whether polygon P is convex or not
    # see: https://stackoverflow.com/questions/471962/how-do-determine-if-a-polygon-is-complex-convex-nonconvex
    N = len(P)
    prods = []
    for k in range(N):
        x0, y0 = P[k]
        x1, y1 = P[(k + 1) % N]
        x2, y2 = P[(k + 2) % N]
        dx1 = x1 - x0
        dy1 = y1 - y0
        dx2 = x2 - x1
        dy2 = y2 - y1
        cross = dx1 * dy2 - dy1 * dx2
        prods.append(cross)
    prods = sorted(prods)
    return prods[0] * prods[-1] > 0


N = int(input())
P = [[int(_) for _ in input().split()] for __ in range(N)]
print(1 if is_convex(P) else 0)