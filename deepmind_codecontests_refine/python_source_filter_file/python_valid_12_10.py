import queue
from math import *
import sys
from collections import *
from random import *
from itertools import *

sys.setrecursionlimit(99999)
eps = sys.float_info.epsilon
P = 2
INF = 1e9 + 1
MOD = 1000000007


def is_prime(n):
    if n == 0 or n == 1:
        return False
    d = 2
    while d * d <= n:
        if n % d == 0:
            return False
        d += 1
    return True


def div_up(n, k):
    if n % k == 0:
        return n // k
    else:
        return n // k + 1


def num_len(n, base=10):
    if n == 0:
        return 1
    return int(floor(log(n, base) + 1))


def dfs_sample(graph, cl, p, v):
    cl[v] = 1
    for to in graph[v]:
        if cl[to] == 1 and p[v] != to:
            # yay, cycle
            pass
        elif cl[to] == 0:
            p[to] = v
            dfs_sample(graph, cl, p, to)
    cl[v] = 2


def down(a):
    for i in range(1, len(a)):
        if a[i] > a[i - 1]:
            return False
    return True


def up(a):
    for i in range(1, len(a)):
        if a[i] < a[i - 1]:
            return False
    return True


def code(c):
    return ord(c) - 32


def _hash_(s):
    res, p = 0, 1
    for i in range(len(s)):
        res += (code(s[i]) * p)
        res %= MOD
        p *= P
        p %= MOD
    return res % MOD


def remove_edge(v, u, graph):
    graph[v].remove(u)
    graph[u].remove(v)


def dfs_stack(start, graph, visited, flags):
    global b
    stack = []
    visited[start] = True
    stack.append(start)
    while len(stack) != 0:
        v = stack.pop()
        if not flags[v]:
            b = False
        for to in graph[v]:
            if not visited[to]:
                visited[to] = True
                stack.append(to)


def all_eq(a):
    for i in range(len(a) - 1):
        if a[i] != a[i + 1]:
            return False
    return True


def solve():
    n, m, k = map(int, input().split())
    if n % 2 == 0 and m % 2 == 0:
        if k % 2 == 0:
            print('YES')
        else:
            print('NO')
    elif n % 2 != 0 and m % 2 == 0:
        if n == 1:
            if n == 2 * k:
                print('YES')
            else:
                print('NO')
        else:
            if k < m // 2:
                print('NO')
            elif (k - m // 2) % 2 == 0:
                print('YES')
            else:
                print('NO')
    else:
        k = (n * m - 2 * k) // 2
        n, m = m, n
        if n == 1:
            if n == 2 * k:
                print('YES')
            else:
                print('NO')
        else:
            if k < m // 2:
                print('NO')
            elif (k - m // 2) % 2 == 0:
                print('YES')
            else:
                print('NO')


for _ in range(int(input())):
    solve()


def debug():
    pass

# debug()