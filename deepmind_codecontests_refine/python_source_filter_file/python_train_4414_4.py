from math import sqrt

x = [0] * 3
y = [0] * 3
r = [0] * 3
for i in range(3):
    x[i], y[i], r[i] = map(int, input().split())
traj = []
for i in range(2):
    sc = r[i + 1]**2 - r[i]**2
    xc = r[i + 1]**2 * x[i] - r[i]**2 * x[i + 1]
    yc = r[i + 1]**2 * y[i] - r[i]**2 * y[i + 1]
    fc = (x[i + 1] * r[i])**2 + (y[i + 1] * r[i])**2 - (x[i] * r[i + 1])**2 - (y[i] * r[i + 1])**2
    if sc != 0:
        xc /= sc
        yc /= sc
        fc /= sc
        fc += xc**2 + yc**2
        if fc < 0:
            exit()
    else:
        xc *= 2
        yc *= 2
    traj.append([sc == 0, xc, yc, fc])
if not traj[0][0] and not traj[1][0]:
    x0, y0, r0 = traj[0][1:]
    x1, y1, r1 = traj[1][1:]
    traj[0] = [True, 2 * (x1 - x0), 2 * (y1 - y0), r0 - r1 - x0**2 - y0**2 + x1**2 + y1**2]
if not traj[0][0]:
    traj[0], traj[1] = traj[1], traj[0]
if traj[0][0] and traj[1][0]:
    a0, b0, c0 = traj[0][1:]
    a1, b1, c1 = traj[1][1:]
    det = a0 * b1 - a1 * b0
    if det != 0:
        print('%.6f %.6f' % (-(c0 * b1 - c1 * b0) / det, (a0 * c1 - a1 * c0) / det))
    exit()
a0, b0, c0 = traj[0][1:]
x1, y1, r1 = traj[1][1:]
if (a0 * x1 + b0 * y1 - c0)**2 > r1 * (a0**2 + b0**2):
    exit()
sdist = (a0 * x1 + b0 * y1 - c0) / (a0**2 + b0**2)
px, py = x1 - a0 * sdist, y1 - b0 * sdist
clen = sqrt(r1 - sdist * (a0 * x1 + b0 * y1 - c0))
nlen = sqrt(a0**2 + b0**2)
points = []
for mul in (-1, 1):
    points.append((px + mul * b0 * clen / nlen, py - mul * a0 * clen / nlen))
if (points[0][0] - x[0])**2 + (points[0][1] - y[0])**2 > (points[1][0] - x[0])**2 + (points[1][1] - y[0])**2:
    points[0], points[1] = points[1], points[0]
print('%.6f %.6f' % points[0])
