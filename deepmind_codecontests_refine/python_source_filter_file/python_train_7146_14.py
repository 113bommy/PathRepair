r, x1, y1, x2, y2 = map(float, input().split())
d2 = (x2 - x1) ** 2 + (y2 - y1) ** 2
if d2 >= r * r:
    print(x1, y1, r)
    exit(0)
if x1 == x2 and y1 == y2:
    print(x1 + 0.5 * r, y1 + 0.5 * r, r)
    exit(0)
d2 = d2 ** 0.5
c = (d2 + r) / (2 * d2)
print(x2 + (x1 - x2) * c, y2 + (y1 - y2) * c, (d2 + r) / 2)
