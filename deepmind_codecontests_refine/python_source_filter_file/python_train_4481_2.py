#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
input:
5 6
0 1
1 0
1 2
2 4
4 3
3 2
4
0 1
0 3
2 3
3 4

output:
1
0
1
1
"""
import sys

sys.setrecursionlimit(int(1e4))


def generate_adj_table(_v_info):
    for v_detail in _v_info:
        v_from, v_to = map(int, v_detail)
        init_adj_table[v_from].append(v_to)
    return init_adj_table


def graph_dfs(u, low, disc, stack_member, st):
    global Time
    # Initialize discovery time and low value
    disc[u] = Time
    low[u] = Time
    Time += 1
    stack_member[u] = True
    st.append(u)
    scc_set = set()

    # Go through all vertices adjacent to this
    for v in adj_table[u]:

        # If v is not visited yet, then recur for it
        if disc[v] == -1:

            graph_dfs(v, low, disc, stack_member, st)

            # Check if the subtree rooted with v has a connection to
            # one of the ancestors of u
            # Case 1 (per above discussion on Disc and Low value)
            low[u] = min(low[u], low[v])

        elif stack_member[v]:

            '''Update low value of 'u' only if 'v' is still in stack
            (i.e. it's a back edge, not cross edge).
            Case 2 (per above discussion on Disc and Low value) '''
            low[u] = min(low[u], disc[v])

    # head node found, pop the stack and print an SCC
    w = -1  # To store stack extracted vertices
    if low[u] == disc[u]:
        while w != u:
            w = st.pop()
            scc_set.add(w)
            stack_member[w] = False
        ans.append(scc_set)

    return None


def scc():
    # Mark all the vertices as not visited
    # and Initialize parent and visited,
    # and ap(articulation point) arrays
    disc = [-1] * vertices
    low = [-1] * vertices
    stack_member = [False] * vertices
    st = []

    # Call the recursive helper function
    # to find articulation points
    # in DFS tree rooted with vertex 'i'
    for v in range(vertices):
        if disc[v] == -1:
            graph_dfs(v, low, disc, stack_member, st)

    return ans


def solve():
    for question in q_list:
        flag = False
        ele1, ele2 = map(int, question)
        for each in scc_sets:
            if (ele1 in each) and (ele2 in each):
                flag = True
        if flag:
            print('1')
        else:
            print('0')
    return None


if __name__ == '__main__':
    _input = sys.stdin.readlines()
    vertices, edges = map(int, _input[0].split())
    v_info = map(lambda x: x.split(), _input[1:edges + 1])
    q_num = int(_input[edges + 1])
    q_list = map(lambda x: x.split(), _input[edges + 2:])

    init_adj_table = tuple([] for _ in range(vertices))
    adj_table = generate_adj_table(v_info)

    Time = 0
    ans = []
    scc_sets = scc()
    solve()