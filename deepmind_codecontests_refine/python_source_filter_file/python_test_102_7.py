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
# sys.setrecursionlimit(1000000000)
inf = float('inf')
eps = 10 ** (-15)
dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]

#############
# Main Code #
#############

T = getN()
for _ in range(T):
    N, M = getNM()
    C = input()
    y, x = 0, 0
    ans = [1, 1] # 初期位置
    rang = [[0, 0], [0, 0]] # yとxのmax
    for c in C:
        if c == 'L':
            x -= 1
            rang[1][0] = min(rang[1][0], x)
        elif c == 'R':
            x += 1
            rang[1][1] = max(rang[1][1], x)
        elif c == 'U':
            y -= 1
            rang[0][0] = min(rang[0][0], y)
        else:
            y += 1
            rang[0][1] = max(rang[0][1], y)

        if rang[0][1] - rang[0][1] + 1 > N or rang[1][1] - rang[1][0] + 1 > M:
            break
        
        ans = [1 - rang[0][0], 1 - rang[1][0]]

    print(*ans)