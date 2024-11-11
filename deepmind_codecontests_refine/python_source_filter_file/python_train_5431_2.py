from sys import stdin
from math import floor, ceil

if __name__ == '__main__':
    n = int(input())
    aa = map(float, stdin.readlines())
    acc = 0
    res = []
    for a in aa:
        f = floor(a)
        c = ceil(a)
        if c - a <= acc + 0.0000000001:
            res.append(str(c))
            acc -= c - a
        else:
            res.append(str(f))
            acc += a - f

    print("\n".join(res))
