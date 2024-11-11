def getN():
    return int(input())
def getNM():
    return map(int, input().split())
def getList():
    return list(map(int, input().split()))
def getArray(intn):
    return [int(input()) for i in range(intn)]
def input():
    return sys.stdin.readline().rstrip()
def rand_N(ran1, ran2):
    return random.randint(ran1, ran2)
def rand_List(ran1, ran2, rantime):
    return [random.randint(ran1, ran2) for i in range(rantime)]
def rand_ints_nodup(ran1, ran2, rantime):
  ns = []
  while len(ns) < rantime:
    n = random.randint(ran1, ran2)
    if not n in ns:
      ns.append(n)
  return sorted(ns)

def rand_query(ran1, ran2, rantime):
  r_query = []
  while len(r_query) < rantime:
    n_q = rand_ints_nodup(ran1, ran2, 2)
    if not n_q in r_query:
      r_query.append(n_q)
  return sorted(r_query)

from collections import defaultdict, deque, Counter
from sys import exit
from decimal import *
from heapq import heapify, heappop, heappush
from math import sqrt
from fractions import gcd
import random
import string
import copy
from itertools import combinations, permutations, product
from operator import mul, itemgetter
from functools import reduce
from bisect import bisect_left, bisect_right

import sys
sys.setrecursionlimit(1000000000)
mod = 10 ** 9 + 7

#############
# Main Code #
#############

x1, y1, x2, y2 = getNM()
place = [(x1, y1, 0)]
N = getN()
for i in range(N):
    x, y, r = getNM()
    place.append((x, y, r))
place.append((x2, y2, 0))
N += 2
# 地点~円の中心 - 円の半径が被曝する時間　これを元にエッジを貼る
# これを最小化したい
# startからいくつかの円を経由してgoalまで行く時の最小距離

def calc(x1, y1, x2, y2):
    return ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5

def dijkstra(n, start):
    dist = [float('inf')] * n
    pos = [(0, start)]
    heapify(pos)
    dist[start] = 0

    while len(pos):
        cost, u = heappop(pos)

        if dist[u] < cost:
            continue
        # エッジは探索のたびに生成していく
        for i in range(N):
            if i == u:
                continue
            dis = calc(place[u][0], place[u][1], place[i][0], place[i][1])
            opt = max(dis - place[u][2] - place[i][2], 0)
            if dist[u] + opt < dist[i]:
                dist[i] = dist[u] + opt
                heappush(pos, (dist[u] + opt, i))

    return dist

print(dijkstra(N, 0)[-1])