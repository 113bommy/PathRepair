import math


def dist(x1, y1, x2, y2):
    return math.sqrt((x2 - x1) ** 2 + (y1 - y2) ** 2)


n, a = map(int, input().split())
l = 10
coord = [[] for i in range(n)]
for i in range(n):
    deg = (360 / n * i) / 180 * math.pi
    coord[i] = [math.cos(deg) * l, math.sin(deg) * l]
m = 200
l = 1
r = 2
eps = 10 ** -6

for i in range(n - 2):
    while math.acos(((coord[l][0] - 10) * (coord[r][0] - 10) + coord[l][1] * coord[r][1]) / (dist(coord[0][0], coord[0][1], coord[l][0], coord[l][1]) * dist(coord[0][0], coord[0][1], coord[r][0], coord[r][1]))) < a / 180 * math.pi and r < n - 1:
        r += 1
    tmp1 = ((coord[l][0] - 10) * (coord[r][0] - 10) + coord[l][1] * coord[r][1]) / (dist(coord[0][0], coord[0][1], coord[l][0], coord[l][1]) * dist(coord[0][0], coord[0][1], coord[r][0], coord[r][1]))
    if tmp1 > 0:
        tmp1 -= eps
    else:
        tmp1 += eps
    tmp2 = ((coord[l][0] - 10) * (coord[r - 1][0] - 10) + coord[l][1] * coord[r - 1][1]) / (dist(coord[0][0], coord[0][1], coord[l][0], coord[l][1]) * dist(coord[0][0], coord[0][1], coord[r - 1][0], coord[r - 1][1]))
    if tmp2 > 0:
        tmp2 -= eps
    else:
        tmp2 += eps
    d1 = abs(math.acos(tmp1) - a / 180 * math.pi)
    d2 = abs(math.acos(tmp2) - a / 180 * math.pi)
    if r > l + 1:
        if m > min(d1, d2):
            if d1 < d2:
                m = d1
                res = str(l + 1) + ' 1 ' + str(r + 1)
            else:
                m = d2
                res = str(l + 1) + ' 1 ' + str(r)
    else:
        if m > d1:
            m = d1
            res = str(l + 1) + ' 1 ' + str(r + 1)
    l += 1
    r = max(r, l + 1)
print(res)