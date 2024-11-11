#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""

input:
5 4
0 1
1 2
2 3
3 4

output:
1
2
3
"""

import sys

sys.setrecursionlimit(int(3e6))
UNVISITED, VISITED_IN_STACK, POPPED_OUT = 0, 1, 2


def generate_adj_table(_v_info):
    for v_detail in _v_info:
        v_from, v_to = map(int, v_detail)
        init_adj_table[v_from].append(v_to)
        # undirected graph
        init_adj_table[v_to].append(v_from)
    return init_adj_table


def graph_dfs(current, prev):
    global timer
    pre_v[current] = lowest_v[current] = timer
    timer += 1

    color[current] = VISITED_IN_STACK
    for adj in adj_table[current]:
        if color[adj] is UNVISITED:
            parent_v[adj] = current
            # recursive dfs
            graph_dfs(adj, current)
            lowest_v[current] = min(lowest_v[current], lowest_v[adj])
        elif adj is not prev:
            lowest_v[current] = min(lowest_v[current], pre_v[adj])

    return None


def art_points():
    graph_dfs(dfs_root, -1)

    np = 0
    for v in range(1, vertices):
        parent = parent_v[v]
        if parent is dfs_root:
            np += 1
        elif pre_v[parent] <= lowest_v[v]:
            art_set.add(parent)

    if np > 1:
        art_set.add(dfs_root)

    return art_set


if __name__ == '__main__':
    _input = sys.stdin.readlines()
    vertices, edges = map(int, _input[0].split())
    v_info = map(lambda x: x.split(), _input[1:])
    pre_v, parent_v, lowest_v = ([float('inf')] * vertices for _ in range(3))
    init_adj_table = tuple([] for _ in range(vertices))

    timer = 1
    # root
    dfs_root = 0

    art_set = set()
    color = [UNVISITED] * vertices

    adj_table = generate_adj_table(v_info)

    res = art_points()
    print('parent', parent_v, 'preorder', pre_v, 'postorder', lowest_v)
    if not res:
        pass
    else:
        print(*sorted(res), sep='\n')