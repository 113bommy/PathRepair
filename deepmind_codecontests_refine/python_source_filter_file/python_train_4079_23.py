import sys
import math
q = int(sys.stdin.readline())

for _ in range(q):
    n = int(sys.stdin.readline())
    minx = -10**5
    maxx = 10**5
    maxy = 10**5
    miny = -10**5
    for _ in range(n):
        x, y, f1, f2, f3, f4 = map(int, sys.stdin.readline().split())

        if f1 == 1 and f2 == 1 and f3 == 1 and f4 == 1:
            continue
        if f1 == 0:  # west
            minx = max(minx, x)

        if f2 == 0:  # north
            maxy = min(maxy, y)

        if f3 == 0:  # east
            maxx = min(maxx, x)
        if f4 == 0:  # south
            miny = max(miny, y)

    if minx > maxx or miny > maxy:
        print(0)
    else:
        print(maxx, miny)
