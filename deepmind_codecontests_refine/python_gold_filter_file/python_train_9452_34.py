n,m,p = map(int,input().split())
graph = [[] for _ in range(n)]
INF = float("inf")
dist = [INF]*n
dist[0] = 0

for _ in range(m):
	f,t,c = map(int,input().split())
	graph[f-1].append((t-1,p-c))
#print(graph)

for _ in range(n):
	update = False
	for f,e in enumerate(graph):
		for t,c in e:
			if dist[f] != INF and dist[t] > dist[f] + c:
				dist[t] = dist[f] + c
				update = True
	if not update:
		break
else:
	prev = dist[-1]
	for _ in range(n):
		for f,e in enumerate(graph):
			for t,c in e:
				if dist[f] != INF and dist[t] > dist[f] + c:
					dist[t] = -INF
	if dist[-1] != prev:
		print(-1)
		exit()
#print(dist)

print(max(0,dist[-1]*(-1)))
