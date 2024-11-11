
import sys
from collections import deque, defaultdict
import copy
import bisect
sys.setrecursionlimit(10 ** 9)
import math
import heapq
from itertools import product, permutations,combinations
import fractions
from operator import itemgetter


import sys
def input():
	return sys.stdin.readline().strip()

N, M = list(map(int, input().split()))

graph = [[] for _ in range(N)]

for _ in range(M):
	s, t = list(map(int, input().split()))
	graph[s - 1].append(t - 1)

base_dist = [-1]*N
base_dist[-1] = 0


for i in range(N - 2, -1, -1):
	total = 0
	for node in graph[i]:
		total += base_dist[node]
	base_dist[i] = total/len(graph[i]) + 1


ans = base_dist[0]
for stop in range(0, N - 1):
	dist = copy.deepcopy(base_dist)
	total = 0
	if len(graph[stop]) == 1:
		continue
	max_d = 0
	for node in graph[stop]:
		max_d = max(max_d, dist[node])
		total += dist[node]
	total -= max_d
	total /= (len(graph[stop]) - 1)
	total += 1
	dist[stop] = total

	for i in range(stop - 1, -1, -1):
		total = 0
		for node in graph[i]:
			total += dist[node]
		dist[i] = total / len(graph[i]) + 1

	ans = min(ans, dist[0])
	#print(stop,dist)

print(ans,graph)