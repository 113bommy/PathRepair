import math
def dist(x1, y1, x2, y2):
    return math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)
def angle(a, b, c):
    return math.acos((a * a + b * b - c * c) / (2 * a * b))
def f(a, b):
    if b > a:
        return f(b, a)
    if abs(b) < 1 / 10000000:
        return a
    else:
        k = int(a / b)
        a -= k * b;
        return f(b, a)
x = [0] * 3
y = [0] * 3
len = [0] * 3
ang = [0] * 3
for i in range(3):
    x[i], y[i] = map(float, input().split())
for i in range(3):
    len[i] = dist(x[i], y[i], x[(i + 1) % 3], y[(i + 1) % 3])
len.sort()
for i in range(3):
    ang[i] = angle(len[i], len[(i + 1) % 3], len[(i + 2) % 3])
ang.sort()
an = f(f(ang[0], ang[1]), ang[2]) * 2
n = 2 * math.pi / an
a = len[0] * math.sin(an / 2) / math.sin(ang[0])
s = n * a * a / (4 * math.tan(an / 2))
print("%.9f" % (s))

#71.756151 7.532275
#-48.634784 100.159986
#91.778633 158.107739
