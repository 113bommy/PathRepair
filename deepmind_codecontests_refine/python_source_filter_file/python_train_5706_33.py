###############################################################################

from sys import stdout
from bisect import bisect_left as binl
from copy import copy, deepcopy
from collections import defaultdict
import math


mod = 1


def intin():
    input_tuple = input().split()
    if len(input_tuple) <= 1:
        return int(input_tuple[0])
    return tuple(map(int, input_tuple))


def intina():
    return [int(i) for i in input().split()]


def intinl(count):
    return [intin() for _ in range(count)]


def modadd(x, y):
    global mod
    return (x + y) % mod


def modmlt(x, y):
    global mod
    return (x * y) % mod


def mod_inv(x):
    # available only when mod is prime
    global mod
    return pow(x, mod - 2, mod)


def gcm(x, y):
    while y != 0:
        z = x % y
        x = y
        y = z
    return x


def combination(x, y):
    assert(x >= y)

    ret = math.factorial(x)
    ret = ret // (math.factorial(x - y) * math.factorial(y))

    return ret


def get_divisors(x):
    retlist = []
    for i in range(1, int(x**0.5) + 3):
        if x % i == 0:
            retlist.append(i)
            retlist.append(x // i)
    return retlist


def get_factors(x):
    retlist = []
    for i in range(2, int(x**0.5) + 3):
        while x % i == 0:
            retlist.append(i)
            x = x // i
    retlist.append(x)
    return retlist


def make_linklist(xylist):
    linklist = {}
    for a, b in xylist:
        linklist.setdefault(a, [])
        linklist.setdefault(b, [])
        linklist[a].append(b)
        linklist[b].append(a)
    return linklist


def calc_longest_distance(linklist, v=1):
    distance_list = {}
    distance_count = 0
    distance = 0
    vlist_previous = []
    vlist = [v]
    nodecount = len(linklist)

    while distance_count < nodecount:
        vlist_next = []
        for v in vlist:
            distance_list[v] = distance
            distance_count += 1
            vlist_next.extend(linklist[v])
        distance += 1
        vlist_to_del = vlist_previous
        vlist_previous = vlist
        vlist = list(set(vlist_next) - set(vlist_to_del))

    max_distance = -1
    max_v = None
    for v, distance in distance_list.items():
        if distance > max_distance:
            max_distance = distance
            max_v = v

    return (max_distance, max_v)


def calc_tree_diameter(linklist, v=1):
    _, u = calc_longest_distance(linklist, v)
    distance, _ = calc_longest_distance(linklist, u)
    return distance


class UnionFind:

    def __init__(self, n):
        self.parent = [i for i in range(n)]

    def root(self, i):
        if self.parent[i] == i:
            return i
        self.parent[i] = self.root(self.parent[i])
        return self.parent[i]

    def unite(self, i, j):
        rooti = self.root(i)
        rootj = self.root(j)
        if rooti == rootj:
            return
        if rooti < rootj:
            self.parent[rootj] = rooti
        else:
            self.parent[rooti] = rootj

    def same(self, i, j):
        return self.root(i) == self.root(j)


###############################################################################


def find_edge(plus, nt, minus):
    ret = []
    if plus is not None and nt is not None and plus <= nt:
        ret.append(nt - plus)
    if minus is not None and nt is not None and minus >= nt:
        ret.append(minus - nt)
    if plus is not None and minus is not None and plus <= minus:
        ret.append((minus - plus) / 2)
    return ret


def calc_coord(t, plus, nt, minus, ismax=False):
    check = []
    if plus is not None:
        check.append(plus + t)
    if nt is not None:
        check.append(nt)
    if minus is not None:
        check.append(minus - t)
    if ismax:
        return max(check)
    return min(check)


def main():
    n = intin()
    xydlist = []
    for _ in range(n):
        line = input()
        line = line.split()
        x = int(line[0])
        y = int(line[1])
        d = line[2]
        xydlist.append((x, y, d))

    xplusmax = None
    xminusmax = None
    xntmax = None

    xplusmin = None
    xminusmin = None
    xntmin = None

    yplusmax = None
    yminusmax = None
    yntmax = None

    yplusmin = None
    yminusmin = None
    yntmin = None

    for x, y, d in xydlist:
        if d == 'R':
            xplusmax = x if xplusmax is None else max(xplusmax, x)
            yntmax = y if yntmax is None else max(yntmax, y)
            xplusmin = x if xplusmin is None else min(xplusmin, x)
            yntmin = y if yntmin is None else min(yntmin, y)
        if d == 'L':
            xminusmax = x if xminusmax is None else max(xminusmax, x)
            yntmax = y if yntmax is None else max(yntmax, y)
            xminusmin = x if xminusmin is None else min(xminusmin, x)
            yntmin = y if yntmin is None else min(yntmin, y)
        if d == 'U':
            xntmax = x if xntmax is None else max(xntmax, x)
            yplusmax = y if yplusmax is None else max(yplusmax, y)
            xntmin = x if xntmin is None else min(xntmin, x)
            yplusmin = y if yplusmin is None else min(yplusmin, y)
        if d == 'D':
            xntmax = x if xntmax is None else max(xntmax, x)
            yminusmax = y if yminusmax is None else max(yminusmax, y)
            xntmin = x if xntmin is None else min(xntmin, x)
            yminusmin = y if yminusmin is None else min(yminusmin, y)

    tlist = []
    tlist.extend(find_edge(xplusmax, xntmax, xminusmax))
    tlist.extend(find_edge(xplusmin, xntmin, xminusmin))
    tlist.extend(find_edge(yplusmax, yntmax, yminusmax))
    tlist.extend(find_edge(yplusmin, yntmin, yminusmin))

    tlist = list(set(tlist))
    ans = float('inf')

    for t in tlist:
        x_max = calc_coord(t, xplusmax, xntmax, xminusmax, ismax=True)
        x_min = calc_coord(t, xplusmin, xntmin, xminusmin, ismax=False)
        y_max = calc_coord(t, yplusmax, yntmax, yminusmax, ismax=True)
        y_min = calc_coord(t, yplusmin, yntmin, yminusmin, ismax=False)
        ans = min(ans, (x_max - x_min) * (y_max - y_min))

    if ans == float('inf'):
        print(0)
    else:
        print(ans)


if __name__ == '__main__':
    main()
