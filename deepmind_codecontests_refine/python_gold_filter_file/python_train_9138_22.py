N = int(input())
graph = []
for _ in range(N):
	graph.append(list(map(int, input().strip())))

def check(graph):
	queue = [0]
	dists = [None] * N
	dists[0] = 0
	while queue:
		cur = queue.pop()
		dist = dists[cur] + 1
		col = graph[cur]
		for i in range(N):
			c = col[i]
			if c == 1:
				d = dists[i]
				if d == None:
					dists[i] = dist
					queue.append(i)
				else:
					if d % 2 != dist %2:
						return False
					elif d > dist:
						dists[i] = dist
						queue.append(i)
	return True

def search(graph, start):
	queue = [start]
	dists = [None] * N
	dists[start] = 0
	while queue:
		cur = queue.pop()
		dist = dists[cur] + 1
		col = graph[cur]
		for i in range(N):
			c = col[i]
			if c == 1:
				d = dists[i]
				if d == None or d > dist:
					dists[i] = dist
					queue.append(i)
	return max(dists)

if check(graph):
	diam = 0
	for i in range(N):
		d = search(graph, i)
		if d > diam:
			diam = d
	print(diam + 1)
else:
	print(-1)
