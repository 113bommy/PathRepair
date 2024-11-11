import math


def read():
    return [int(x) for x in input().split()]


def dist(x1, y1, x2, y2):
    return math.sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2))


def main():
    a, b = read()
    n, = read()

    res = None
    for i in range(0, n):
        x, y, v = read()
        d = dist(a, b, x, y)/v
        if res is None or res > d:
            res = d

    print(d)


main()