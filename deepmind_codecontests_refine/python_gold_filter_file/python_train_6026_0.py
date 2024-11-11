# AOJ 0117 A reward for a Carpenter
# Python3 2018.6.21 bal4u

INF = 0x7fffffff

import heapq
def dijkstra(V, to, start, goal):
	dist = [INF]*V
	Q = []
	dist[start] = 0
	heapq.heappush(Q, (0, start))
	while len(Q):
		t, s = heapq.heappop(Q)
		if s == goal: break
		if dist[s] < t: continue
		for i in to[s]:
			e, cost = i
			nt = t + cost
			if dist[e] > nt:
				dist[e] = nt
				heapq.heappush(Q, (nt, e))
	return dist[goal]

n = int(input())+1
to = [[] for i in range(n)]
for i in range(int(input())):
	a, b, c, d = list(map(int, input().split(',')))
	to[a].append((b, c))
	to[b].append((a, d))
s, g, V, P = list(map(int, input().split(',')))
if s == g: print(V-P)
else: print(V-P - dijkstra(n, to, s, g) - dijkstra(n, to, g, s))
