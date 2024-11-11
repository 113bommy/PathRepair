#!/usr/bin/env python3
"""
This file is part of https://github.com/cheran-senthil/PyRival
Copyright 2019 Cheran Senthilkumar <hello@cheran.io>

"""
import os
import sys
from atexit import register
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
sys.__stdout__ = BytesIO()
register(lambda: os.write(1, sys.__stdout__.getvalue()))

res = 0


def main():
    n = int(input())
    a = input().split()

    red_cnt = a.count('1')
    blue_cnt = a.count('2')

    tree = [[] for _ in range(n)]
    for _ in range(n - 1):
        v, u = map(int, input().split())
        tree[v - 1].append(u - 1)
        tree[u - 1].append(v - 1)

    dp, visited = [[0, 0] for _ in range(n)], [False] * n

    def dfs(node):
        global res

        finished = [False] * n
        stack = [node]
        while stack:
            node = stack[-1]
            node_cnt = dp[node]

            if not visited[node]:
                visited[node] = True
            else:
                stack.pop()
                node_cnt[0] += a[node] == '1'
                node_cnt[1] += a[node] == '2'
                finished[node] = True

            for child in tree[node]:
                if not visited[child]:
                    stack.append(child)
                elif finished[child]:
                    child_cnt = dp[child]
                    node_cnt[0] += child_cnt[0]
                    node_cnt[1] += child_cnt[1]

                    if ((child_cnt[0] == red_cnt) and (child_cnt[1] == 0)) or ((child_cnt[0] == 0) and
                                                                               (child_cnt[1] == blue_cnt)):
                        res += 1

    dfs(0)
    print(res)


if __name__ == '__main__':
    main()
