#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
input:
3 4 6
0 0
0 2
0 3
1 1
2 1
2 3

output:
3
"""

import sys


def generate_adj_table(_edges):
    for edge in _edges:
        vx, vy = map(int, edge)
        init_adj_table[vx].append(vy)

    return init_adj_table


def graph_dfs(current, matching, visited):
    for adj in range(y_num):
        if adj in adj_table[current] and not visited[adj]:
            visited[adj] = True
            if matching[adj] == -1 or graph_dfs(matching[adj], matching, visited):
                matching[adj] = current
                return True
    return False


def mbm():
    matching = [-1] * y_num
    res = 0
    for v in range(x_num):
        visited = [False] * y_num
        if graph_dfs(v, matching, visited):
            res += 1
    print(matching)
    return res


if __name__ == '__main__':
    _input = sys.stdin.readlines()
    x_num, y_num, e_num = map(int, _input[0].split())
    edges = map(lambda x: x.split(), _input[1:])

    v_num = x_num + y_num
    init_adj_table = [[] for _ in range(x_num)]
    adj_table = generate_adj_table(edges)
    print(mbm())