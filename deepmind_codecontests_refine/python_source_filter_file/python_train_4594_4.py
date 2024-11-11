from math import sqrt

a, b, c = map(int, input().split())
x1, y1, x2, y2 = map(int, input().split())
res1 = abs(x1 - x2) + abs(y1 - y2)

res2 = 10 ** 9 + 7
res3 = 10 ** 9 + 7
res4 = 10 ** 9 + 7
res5 = 10 ** 9 + 7

if b != 0 and a != 0:
    x = (-y1 * b - c) / a
    y = (-x2 * a - c) / b
    res2 = abs(x1 - x) + abs(y2 - y) + sqrt(abs(x - x2) ** 2 + abs(y1 - y) ** 2)

if a != 0:
    x = (-y1 * b - c) / a
    xx = (-y2 * b - c) / a
    res4 = abs(x1 - x) + abs(x2 - xx) + sqrt(abs(x - xx) ** 2 + abs(y1 - y2) ** 2)

if b != 0:
    y = (-x1 * a - c) / b
    yy = (-x2 * a - c) / b
    res5 = abs(y1 - y) + abs(y2 - yy) + sqrt(abs(y - yy) ** 2 + abs(x1 - x2) ** 2)

if a != 0 and b != 0:
    x = (-y2 * b - c) / a
    y = (-x1 * a - c) / b
    res3 = abs(y1 - y) + abs(x2 - x) + sqrt(abs(x1 - x) ** 2 + abs(y2 - y) ** 2)

print(min(res1, res2, res3, res4, res5))
# print(res1, res2, res3, res4, res5)
