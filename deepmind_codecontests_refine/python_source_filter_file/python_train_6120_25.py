import math

n, k = map(int, input().split())

xyc = []
for _ in range(n):
    x, y, c = map(int, input().split())
    xyc.append((x, y, c))

if k == 1:
    print(0)
    exit()


def get_intersecs(x0, y0, r0, x1, y1, r1):
    # circle 1: (x0, y0), radius r0
    # circle 2: (x1, y1), radius r1

    d=math.sqrt((x1-x0)**2 + (y1-y0)**2)

    # non intersecting
    if d > r0 + r1 :
        return []
    # One circle within other
    if d < abs(r0-r1):
        return []
    # coincident circles
    if d == 0 and r0 == r1:
        return []
    else:
        a=(r0**2-r1**2+d**2)/(2*d)
        if r0 < a:
            return []
        h=math.sqrt(r0**2-a**2)
        x2=x0+a*(x1-x0)/d
        y2=y0+a*(y1-y0)/d
        x3=x2+h*(y1-y0)/d
        y3=y2-h*(x1-x0)/d

        x4=x2-h*(y1-y0)/d
        y4=y2+h*(x1-x0)/d

        return [(x3, y3), (x4, y4)]


def calc(x1, y1, x2, y2, c2):
    return c2 * math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)


def count(x, y, t):
    cnt = 0
    for i in range(n):
        xi, yi, ci = xyc[i]
        if calc(x, y, xi, yi, ci) < t + 0.0000001:
            cnt += 1
            if cnt >= k:
                return cnt
    return cnt


def check(t):
    # 円の中心
    for i in range(n):
        x, y, _ = xyc[i]
        if count(x, y, t) >= k:
            return True
    # 円の交点
    for i in range(n - 1):
        for j in range(i + 1, n):
            x1, y1, c1 = xyc[i]
            x2, y2, c2 = xyc[j]
            intersecs = get_intersecs(x1, y1, t/c1, x2, y2, t/c2)
            for (x, y) in intersecs:
                # print(x, y)
                if count(x, y, t) >= k:
                    return True
    return False


low = 0
high = 10 ** 5
for _ in range(100):
    mid = (high + low) / 2
    if check(mid):
        high = mid
    else:
        low = mid
print((high + low) / 2)
