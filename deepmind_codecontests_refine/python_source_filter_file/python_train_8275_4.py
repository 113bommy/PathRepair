from math import sqrt

a, v = map(int, input().split())
l, d, w = map(int, input().split())
w = min(v, w)
lowtime = (v - w) / a
lowdist = v * lowtime - a * lowtime**2 / 2
startdist = v**2 / (2 * a)
if startdist + lowdist <= d:
    ans = v / a + (d - startdist - lowdist) / v + lowtime
elif w**2 <= 2 * d * a:
    u = sqrt(a * d + w**2 / 2)
    ans = 2 * (u - w) / a
else:
    ans = sqrt(2 * d / a)
    w = ans * a
hightime = (v - w) / a
highdist = w * hightime + a * hightime**2 / 2
if highdist <= l - d:
    ans += hightime + (l - d - highdist) / v
else:
    disc = sqrt(w**2 + 2 * a * (l - d))
    ans += (disc - w) / a
print('%.7f' % ans)
