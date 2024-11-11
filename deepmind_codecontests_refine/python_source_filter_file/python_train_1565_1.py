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

sys.setrecursionlimit(int(1e4))


def dfs_Tarjan(current):
    global timer
    children = 0
    visited[current] = True
    disc[current] = low[current] = timer
    timer += 1

    for adj in adj_table[current]:
        if not visited[adj]:
            parent[adj] = current
            children += 1
            dfs_Tarjan(adj)
            low[current] = min(low[current], low[adj])
            # current vertex is the root of DFS tree
            if parent[current] == -1 and children > 1:
                art_set.add(current)
            elif parent[current] != -1 and low[adj] >= disc[current]:
                art_set.add(current)

        elif adj != parent[current]:
            low[current] = min(low[current], disc[adj])

    return None


def dfs_init():
    for v in range(v_num):
        if not visited[v]:
            dfs_Tarjan(v)

    return None


if __name__ == '__main__':
    _input = sys.stdin.readlines()
    v_num, e_num = map(int, _input[0].split())
    edges = map(lambda x: x.split(), _input[1:])

    adj_table = tuple([] for _ in range(v_num))
    for edge in edges:
        source, target = map(int, edge)
        adj_table[source].append(target)
        adj_table[target].append(source)

    timer = 0
    art_set = set()
    parent = [-1] * v_num
    visited = [False] * v_num
    disc, low = ([float('inf')] * v_num for _ in range(2))

    dfs_init()
    if art_set:
        print(*sorted(art_set), sep='\n')