import logging
from collections import defaultdict


def calc_assigned_edge_nums(n, m, edges, new_comer):
    d_v2n = {}
    v = 1
    for i in range(1, n + 1):
        if i == new_comer:
            d_v2n[i] = 7
        else:
            d_v2n[i] = v
            v += 1
    g = defaultdict(set)
    for a, b in edges:
        na, nb = d_v2n[a], d_v2n[b]
        g[na].add(nb)
        g[nb].add(na)

    for i in range(1, n):
        if len(g[i]) == 0:
            return m
    dominoes = {(a, b) for b in range(1, 7) for a in range(1, b + 1)}

    num_of_already_assigned_dominoes = 0
    for vertex_from, v in g.items():
        for vertex_to in v:
            domino = tuple(sorted([vertex_from, vertex_to]))
            # domino_to_remove = domino
            if domino in dominoes:
                num_of_already_assigned_dominoes += 1
                dominoes.discard(domino)

    logging.debug('remain dominoes {}'.format(dominoes))
    max_assignable_edges_to_7 = 0
    for candidate in range(1, 7):  # assign 1-6 dot for vertex 7
        num_of_assignable_edges = 0
        for vertex_from in g[7]:
            domino = tuple(sorted([vertex_from, candidate]))
            if domino in dominoes:
                num_of_assignable_edges += 1
        max_assignable_edges_to_7 = max(max_assignable_edges_to_7, num_of_assignable_edges)
    return num_of_already_assigned_dominoes + max_assignable_edges_to_7


def solve(n, m, edges=list()):
    if n <= 6:
        return m

    maximum_r = 0
    for i in range(1, n):  # choose which should be new comer
        r = calc_assigned_edge_nums(n, m, edges, i)
        logging.debug('#{}= {}'.format(i, r))
        maximum_r = max(maximum_r, r)
    return maximum_r


_DEBUG = False
if _DEBUG:
    logging.basicConfig(level=logging.DEBUG)
    assert solve(7, 21, [(1, 2), (1, 3), (1, 4), (1, 5), (1, 6), (1, 7), (2, 3), (2, 4), (2, 5), (2, 6), (2, 7), (3, 4),
                         (3, 5), (3, 6), (3, 7), (4, 5), (4, 6), (4, 7), (5, 6), (5, 7), (6, 7)]) == 16
    assert solve(4, 4, [(1, 2), (2, 3), (3, 4), (4, 1)]) == 4
    assert solve(7, 0) == 0
    assert solve(3, 1, [(1, 3)]) == 1
else:
    logging.basicConfig(level=logging.WARN)

_n, _m = map(int, input().split())
_edges = []
for _ in range(_m):
    a, b = map(int, input().split())
    _edges.append([a, b])
print(solve(_n, _m, _edges))
