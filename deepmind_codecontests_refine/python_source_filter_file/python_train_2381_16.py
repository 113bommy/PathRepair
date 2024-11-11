mport sys

for i in sys.stdin.readlines():
    a, b, c, d, e, f = [int(x) for x in i.split()]
    y = (c * d - a * f) / (b * d - a * e)
    x = (c - b * y) / a
    print('{0:.3f} {1:.3f}'.format(x, y))