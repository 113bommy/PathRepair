import sys
import math

n = int(sys.stdin.readline().rstrip())
point = []
for i in range(n):
    ax = list(map(int, sys.stdin.readline().rstrip().split()))
    if ax[0] != 0 or ax[1] != 0:
        point.append(ax)

result = 0
plen = len(point)
if plen == 0:
    print(0)
    exit()

sorted(point, key=lambda x: math.atan2(x[1], x[0]))

point = point + point
for i in range(plen):
    maxdig = 0
    maxp = [0, 0]
    for j in range(i, i + plen):
        tmpp = (maxp[0] + point[j][0]) ** 2 + (maxp[1] + point[j][1]) ** 2
        if maxdig > tmpp:
            if result < maxdig:
                result = maxdig
            break
        else:
            maxdig = tmpp
            maxp[0] += point[j][0]
            maxp[1] += point[j][1]
            if j == i + plen -1 and result < maxdig:
                result = maxdig


print(result ** 0.5)

