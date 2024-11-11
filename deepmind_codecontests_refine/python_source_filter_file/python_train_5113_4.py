def bfs(x):
	visited = [1 for _ in range(2 * n)]
	queue = [0]
	while queue:
		v = queue.pop(0)
		
		if v == x or v == 2 * n - x + 1:
			return "YES"
		
		for next in G[v]:
			if visited[next]:
				visited[next] = 0
				queue.append(next)
	return "NO"


n, x = map(int, input().split())
lineUp = list(map(int, input().split()))
lineDown = list(map(int, input().split()))

G = [[] for _ in range(n * 2)]
for i in range(n):
	if lineUp[i]:
		try:
			G[last1].append(i)
		except:
			None
				
		last1 = i
	if lineDown[n - i - 1]:
		try:
			G[last2].append(n + i)
		except:
			None
		last2 = n + i
	
	if lineUp[i] and lineDown[i]:
		G[i].append(2 * n - i - 1)
		
		G[2 * n - i - 1].append(i)

print(bfs(x - 1))
