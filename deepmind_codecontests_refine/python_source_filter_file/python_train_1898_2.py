from sys import stdin, exit
from collections import deque
import operator 




# Want to find the shortest path from 1 to n
# Can use BFS...

'''
def distanceTo(node, end):
	zz = True 
	visit = [0]*(N + 1)
	visit[node] = 1
	pred = [0]*(N + 1)
	check = [node]

	if node == end:
		return 0

	c = 0
	while zz:
		next_check = []
		for node in range(len(check)):
			v = check.pop()
			for neigh in vertex[v]:

				if visit[neigh] == 0:
					visit[neigh] = 1
					if neigh == end:
						zz = False 
						break 
					else: 
						next_check.append(neigh)

		c += 1
		check = next_check 
	return c
'''

# Edit 2/28 11:11 AM - Using a new BFS algorithm
# 11:15 - Still a TLe on Test 6
def bfs(s):
	q = deque()
	d = [-1] * (N + 1)
	q.append(s)
	d[s] = 0
	while len(q) > 0:
		u = q.popleft()
		for v in vertex[u]:
			if d[v] == -1:
				d[v] = d[u] + 1
				q.append(v)
	return d





# Create graph information


N, M, K = map(int, stdin.readline().split())
special = [int(x) for x in stdin.readline().split()]

'''
vertex = {}
for _ in range(M):
	v, w = map(int, stdin.readline().split())
	try:
		vertex[v].append(w)
	except:
		vertex[v] = [w]
	try:
		vertex[w].append(v)
	except:
		vertex[w] = [v]
'''

# Edit 2/28 11:08 AM - Maybe we have TLE due to vertex dictionary
# Still TLE on Test 6
vertex = [[] for _ in range(N + 1)]
for i in range(M):
	x, y = map(int, stdin.readline().split())
	vertex[x].append(y)
	vertex[y].append(x)



# Doing BFS on the graph to find all the shortest paths
'''
short_dist = distanceTo(1, N)


dist_pairs = []
for node in special:
	dist_pairs.append((distanceTo(node, 1), distanceTo(node, N)))

dist_pairs.sort(key=operator.itemgetter(0))


for i in range(K - 1):
	x_1, y_1 = dist_pairs[i]
	x_2, y_2 = dist_pairs[i + 1]
	if y_1 <= y_2:
		print (short_dist)
		exit()

maxx = 0
for i in range(K - 1):
	x_1, y_1 = dist_pairs[i]
	x_2, y_2 = dist_pairs[i + 1]
	if x_1 + y_2 + 1 <= short_dist:
		if x_1 + y_2 + 1 > maxx:
			maxx = x_1 + y_2 + 1
print (maxx)
'''


# Edit 2/28 11:15 - Edited for new BFS algorithm 
# 11:16 - Still a TLE on Test 6 
d_1 = bfs(1)
d_N = bfs(N)
short_dist = d_1[N]


dist_pairs = []

for node in special:
	dist_pairs.append((d_1[node], d_N[N]))

dist_pairs.sort(key=operator.itemgetter(0))


for i in range(K - 1):
	x_1, y_1 = dist_pairs[i]
	x_2, y_2 = dist_pairs[i + 1]
	if y_1 <= y_2:
		print (short_dist)
		exit()

maxx = 0
for i in range(K - 1):
	x_1, y_1 = dist_pairs[i]
	x_2, y_2 = dist_pairs[i + 1]
	if x_1 + y_2 + 1 <= short_dist:
		if x_1 + y_2 + 1 > maxx:
			maxx = x_1 + y_2 + 1
print (maxx)

























