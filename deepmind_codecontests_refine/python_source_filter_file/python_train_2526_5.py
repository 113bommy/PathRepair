from bisect import bisect_left as bl
from bisect import bisect_right as br
from heapq import heappush,heappop,heapify
import math
from collections import *
from functools import reduce, cmp_to_key
import sys
input = sys.stdin.readline

from itertools import accumulate
from functools import lru_cache

M = mod = 10000
def factors(n):return sorted(set(reduce(list.__add__, ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0))))
def inv_mod(n):return pow(n, mod - 2, mod)
 
def li():return [int(i) for i in input().rstrip('\n').split()]
def st():return input().rstrip('\n')
def val():return int(input().rstrip('\n'))
def li2():return [i for i in input().rstrip('\n')]
def li3():return [int(i) for i in input().rstrip('\n')]


g = 0
def dfs(node):
    global g
    d = deque()
    d.append([node, 0])
    maxdist = 0
    farnode = node
    visited = {}
    while d:
        node, dist = d.popleft()
        visited[node] = 1

        if dist > maxdist:
            maxdist, farnode = dist, node
        
        for j in g[node]:
            if j not in visited:
                visited[j] = 1
                d.append([j, dist + 1])
    return [farnode, maxdist]

def findistance(u, v):
    global g
    d = deque()
    d.append([u, 0])
    visited = {}
    while d:
        node, dist = d.popleft()
        if node == v:return dist
        visited[node] = 1
        for j in g[node]:
            if j not in visited:
                visited[j] = 1
                d.append([j, dist + 1])
    


for _ in range(val()):
    n, a, b, da, db = li()

    g = defaultdict(set)

    for i in range(n - 1):
        u, v = li()
        g[u].add(v)
        g[v].add(u)

    farnode1 = dfs(1)[0]
    diameter = dfs(farnode1)[1]
    # print('Diameter', diameter, 'Speeds : ', da, db, a, b)
    # print('Distance', findistance(a, b))
    print('Bob' if findistance(a, b) > da and diameter > 2 * da and da < db else 'Alice')
