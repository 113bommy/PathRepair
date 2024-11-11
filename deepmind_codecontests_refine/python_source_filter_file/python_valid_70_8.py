from collections import defaultdict, deque, Counter
from heapq import heapify, heappop, heappush
import math
from copy import deepcopy
from itertools import combinations, permutations, product, combinations_with_replacement
from bisect import bisect_left, bisect_right

import sys
def input():
    return sys.stdin.readline().rstrip()
def getN():
    return int(input())
def getNM():
    return map(int, input().split())
def getList():
    return list(map(int, input().split()))
def getListGraph():
    return list(map(lambda x:int(x) - 1, input().split()))
def getArray(intn):
    return [int(input()) for i in range(intn)]

mod = 10 ** 9 + 7
MOD = 998244353
# sys.setrecursionlimit(10000000)
inf = float('inf')
eps = 10 ** (-10)
dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]

#############
# Main Code #
#############

str = {'a': 0, 'b': 1, 'c': 2, 'd': 3, 'e': 4, 'f': 5, 'g': 6, 'h': 7, 'i': 8, 'j': 9, 'k': 10, 'l': 11, 'm': 12, 'n': 13, 'o': 14, 'p': 15, 'q': 16, 'r': 17, 's': 18, 't': 19, 'u': 20, 'v': 21, 'w': 22, 'x': 23, 'y': 24, 'z': 25}
rev = {0: 'a', 1: 'b', 2: 'c', 3: 'd', 4: 'e', 5: 'f', 6: 'g', 7: 'h', 8: 'i', 9: 'j', 10: 'k', 11: 'l', 12: 'm', 13: 'n', 14: 'o', 15: 'p', 16: 'q', 17: 'r', 18: 's', 19: 't', 20: 'u', 21: 'v', 22: 'w', 23: 'x', 24: 'y', 25: 'z'}

T = getN()
for _ in range(T):
    S = [str[s] for s in list(input())]
    N = len(S)
    d = {}
    add = [] # 操作順
    for i in range(N - 1, -1, -1):
        if not S[i] in d:
            d[S[i]] = 1
            add.append(S[i])

    add = list(reversed(add))
    # 長さの判定
    def f(x):
        c = [0] * 26
        res = 0
        for i in range(x):
            c[S[i]] += 1

        all = sum(c)
        for i in range(len(add)):
            res += all
            all -= c[add[i]]
        return res

    ok = 0
    ng = N
    while abs(ng - ok) > 1:
        mid = (ok + ng) // 2
        if f(mid) > N:
            ng = mid
        else:
            ok = mid

    # 実際にやる
    psu = S[:ok]
    ans = ''.join([rev[s] for s in psu])
    t = []
    for i in range(len(add)):
        t += psu
        psu = [s for s in psu if s != add[i]]

    if t == S:
        print(ans, ''.join([rev[s] for s in add]))
    else:
        print(-1)