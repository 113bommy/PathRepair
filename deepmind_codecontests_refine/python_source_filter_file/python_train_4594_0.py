from math import sqrt

def between(a, b, c):
    return (a - c) * (b - c) <= 0

a, b, c = map(int, input().split())
x1, y1, x2, y2 = map(int, input().split())
forw = (x1 < x2) == (y1 < y2)
norm = (a > 0) == (b > 0)
if x1 == x2 or y1 == y2 or a == 0 or b == 0 or forw == norm:
    print(abs(x1 - x2) + abs(y1 - y1))
    exit()
p1 = None
if between(-b * y1, -b * y2, a * x1 + c):
    p1 = (x1, (a * x1 + c) / -b)
if between(-a * x1, -a * x2, b * y1 + c):
    p1 = ((b * y1 + c) / -a, y1)
p2 = None
if between(-b * y1, -b * y2, a * x2 + c):
    p2 = (x2, (a * x2 + c) / -b)
if between(-a * x1, -a * x2, b * y2 + c):
    p2 = ((b * y2 + c) / -a, y2)
if p1 is None or p2 is None:
    print(abs(x1 - x2) + abs(y1 - y1))
    exit()
print('%.8f' % (abs(x1 - p1[0]) + abs(y1 - p1[1]) + abs(x2 - p2[0]) + abs(y2 - p2[1]) + sqrt((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2)))
