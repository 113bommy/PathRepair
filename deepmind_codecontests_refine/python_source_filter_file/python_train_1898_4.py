from heapq import heappush, heappop, heapify
from collections import deque, defaultdict, Counter
import itertools
from itertools import permutations, combinations, accumulate
import sys
import bisect
import string
import math
import time


def I(): return int(input())


def MI(): return map(int, input().split())


def S(): return input()


def MS(): return map(str, input().split())


def LI(): return [int(i) for i in input().split()]


def LI_(): return [int(i)-1 for i in input().split()]


def StoI(): return [ord(i)-97 for i in input()]


def ItoS(nn): return chr(nn+97)


def input(): return sys.stdin.readline().rstrip()


def show(*inp, end='\n'):
    if show_flg:
        print(*inp, end=end)


YN = {False: 'No', True: 'Yes'}
MOD = 10**9+7
inf = float('inf')
IINF = 10**10
l_alp = string.ascii_lowercase
u_alp = string.ascii_uppercase
nums = ['1', '2', '3', '4', '5', '6', '7', '8', '9', '10']

show_flg = False
# show_flg = True


def bfs(graph, initial, n):
    dist = [-1] * (n + 1)
    q = deque([initial])
    visited = [False] * (n + 1)
    visited[initial] = True
    dist[initial] = 0

    while len(q) != 0:
        edge = q.popleft()
        nxt = graph[edge]

        for i, e in enumerate(nxt):
            if visited[e] is False:
                q.append(e)
                dist[e] = dist[edge] + 1
                visited[e] = True

    return dist


def main():
    n, m, k = MI()
    a = LI()
    graph = [[] for i in range(n+1)]
    is_special = {}

    for i in a:
        is_special[i] = True

    for i in range(m):
        x, y = map(int, input().split())
        graph[x].append(y)
        graph[y].append(x)

    dist_1toN = bfs(graph, 1, n)
    dist_Nto1 = bfs(graph, n, n)

    data = [None] * k
    for i in range(len(a)):
        x = dist_1toN[a[i]]
        y = dist_Nto1[a[i]]
        data[i] = (x - y, a[i])

    data.sort()

    best = 0
    maxv = -1
    for d in data:
        a_idx = d[1]
        best = max(best, maxv+dist_Nto1[a_idx])
        maxv = max(maxv, dist_1toN[a_idx])

    print(min(dist_1toN[-1], best+1))


if __name__ == '__main__':
    main()
