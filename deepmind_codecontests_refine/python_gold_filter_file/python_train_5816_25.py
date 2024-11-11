# -*- coding: utf-8 -*-
import bisect
import heapq
import math
import random
import sys
from collections import Counter, defaultdict, deque
from decimal import ROUND_CEILING, ROUND_HALF_UP, Decimal
from functools import lru_cache, reduce
from itertools import combinations, combinations_with_replacement, product, permutations
from operator import add, mul, sub
from pprint import pprint

sys.setrecursionlimit(10000)


def read_int():
    return int(input())


def read_int_n():
    return list(map(int, input().split()))


def read_float():
    return float(input())


def read_float_n():
    return list(map(float, input().split()))


def read_str():
    return input().strip()


def read_str_n():
    return list(map(str, input().split()))


def error_print(*args):
    print(*args, file=sys.stderr)


def mt(f):
    import time

    def wrap(*args, **kwargs):
        s = time.time()
        ret = f(*args, **kwargs)
        e = time.time()

        error_print(e - s, 'sec')
        return ret

    return wrap


def Dijkstra(g, s):
    d = {}
    q = []
    done = set()
    for v in g.keys():
        d[v] = sys.maxsize
    d[s] = 0
    heapq.heappush(q, (d[s], s))

    while q:
        c, u = heapq.heappop(q)
        if u in done:
            continue
        done.add(u)
        for v in g[u]:
            alt = g[u][v] + d[u]
            if d[v] > alt:
                d[v] = alt
                heapq.heappush(q, (d[v], v))
    return d


@mt
def slv(N, XY, YS, XT, YT, XYR):
    p = [(XY, YS, 0, -1), (XT, YT, 0, -2)]
    for i, (x, y, r) in enumerate(XYR):
        p.append((x, y, r, i))

    def cost(p1, p2):
        c = math.sqrt((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2) - p1[2] - p2[2]
        return max(0, c)

    g = defaultdict(dict)
    for i in range(N+2):
        for j in range(N+2):
            if i == j:
                continue
            d = cost(p[i], p[j])
            g[p[i][3]][p[j][3]] = d
            g[p[j][3]][p[i][3]] = d

    return Dijkstra(g, -1)[-2]


def main():
    XS, YS, XT, YT = read_int_n()
    N = read_int()
    XYR = [read_int_n() for _ in range(N)]
    print(slv(N, XS, YS, XT, YT, XYR))


if __name__ == '__main__':
    main()
