N, M = [int(_) for _ in input().split()]
AB = [[int(_) for _ in input().split()] for i in range(N - 1 + M)]

import sys
sys.setrecursionlimit(100000)

from collections import defaultdict

vs = defaultdict(set)

for a, b in AB:
    vs[b].add(a)

cache = {}

def calc(n):
    if n in cache:
        return cache[n]
    max_distance = 0
    max_distance_parent = 0
    for m in vs[n]:
        d = calc(m)[0]
        if max_distance < d + 1:
            max_distance = d + 1
            max_distance_parent = m
    result = max_distance, max_distance_parent
    cache[n] = result
    return result

for i in range(1, N + 1):
    print(i, calc(i))
