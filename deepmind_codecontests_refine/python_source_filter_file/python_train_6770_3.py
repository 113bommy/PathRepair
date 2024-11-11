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
0 1
1 2
2 3
3 4
"""

import sys
# sys.setrecursionlimit(int(3e6))


def generate_adj_table(_v_info):
    for v_detail in _v_info:
        v_from, v_to = map(int, v_detail)
        init_adj_table[v_from].append(v_to)
        # undirected graph
        init_adj_table[v_to].append(v_from)
    return init_adj_table


def graph_dfs(u, visited, parent, low, disc):
    global Time
    # Count of children in current node
    children = 0

    # Mark the current node as visited and print it
    visited[u] = True

    # Initialize discovery time and low value
    disc[u] = Time
    low[u] = Time
    Time += 1

    # Recur for all the vertices adjacent to this vertex
    for v in adj_table[u]:
        # If v is not visited yet, then make it a child of u
        # in DFS tree and recur for it
        if not visited[v]:
            parent[v] = u
            children += 1
            graph_dfs(v, visited, parent, low, disc)

            # Check if the subtree rooted with v has a connection to
            # one of the ancestors of u
            low[u] = min(low[u], low[v])

            ''' If the lowest vertex reachable from subtree
            under v is below u in DFS tree, then u-v is
            a bridge'''
            if low[v] > disc[u]:
                ans.append(sorted([u, v]))
        elif v != parent[u]:  # Update low value of u for parent function calls.
            low[u] = min(low[u], disc[v])

    return None


def bridge():
    visited = [False] * vertices
    disc = [float("Inf")] * vertices
    low = [float("Inf")] * vertices
    parent = [-1] * vertices

    for v in range(vertices):
        if not visited[v]:
            graph_dfs(v, visited, parent, low, disc)

    return ans


if __name__ == '__main__':
    _input = sys.stdin.readlines()
    vertices, edges = map(int, _input[0].split())
    v_info = map(lambda x: x.split(), _input[1:])
    Time = 0
    ans = []

    init_adj_table = tuple([] for _ in range(vertices))
    adj_table = generate_adj_table(v_info)
    res = bridge()
    res.sort()
    for ele in res:
        print(*ele)