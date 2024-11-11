#!/usr/bin/env python3

import itertools
import math


EPS = 1e-6


def dot(a, b):
    return a.real * b.real + a.imag * b.imag


def enclose_triangle(p1, p2, p3):
    v12 = p2 - p1
    v23 = p3 - p2
    v31 = p1 - p3
    an1 = dot(v12, -v31)
    an2 = dot(-v12, v23)
    an3 = dot(-v23, v31)
    if an1 < 0 + EPS or an2 < 0 + EPS or an3 < 0 + EPS:
        vx = max(v12, v23, v31, key=abs)
        rad = abs(vx) / 2
        if vx == v12:
            cent = (p1 + p2) / 2
        elif vx == v23:
            cent = (p2 + p3) / 2
        else:
            cent = (p3 + p1) / 2
    else:
        a = p1
        b = p2
        c = p3
        a2 = abs(v23) ** 2
        b2 = abs(v31) ** 2
        c2 = abs(v12) ** 2
        u = a2 * (b2 + c2 - a2) * a + b2 * (c2 + a2 - b2) * \
            b + c2 * (a2 + b2 - c2) * c
        u /= a2 * (b2 + c2 - a2) + b2 * (c2 + a2 - b2) + c2 * (a2 + b2 - c2)
        rad = abs(u - p1)
        cent = u
    return rad, cent


def enclose_points(n, ps):
    assert n >= 2
    if n == 2:
        return abs(ps[1] - ps[0]) / 2
    for p1, p2, p3 in itertools.combinations(ps, 3):
        rad_cand, cent_cand = enclose_triangle(p1, p2, p3)
        for q1 in ps:
            dist = abs(cent_cand - q1)
            if dist > rad_cand:
                break
        else:
            return rad_cand


def main():
    n = int(input())
    ps = []
    for _ in range(n):
        x, y = (float(z) for z in input().split())
        ps.append(complex(x, y))
    res = enclose_points(n, ps)
    print("{:.16f}".format(res))


if __name__ == "__main__":
    main()
