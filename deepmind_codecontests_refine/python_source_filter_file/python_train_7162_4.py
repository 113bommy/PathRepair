n = int(input())
p = [list(map(int, input().split())) for _ in range(n)]
adj = [[] for _ in range(200000)]
for x, y in p:
	adj[x-1].append(y+99999)
	adj[y+99999].append(x-1)

visited = [False for _ in range(200000)]

def dfs(orig):
	stack = [orig]
	edges = len(adj[orig])
	if orig < 100000:
		x_num, y_num = 1, 0
	else:
		x_num, y_num = 0, 1

	while stack:
		v = stack.pop()
		for w in adj[v]:
			if visited[w] == False:
				visited[w] = True
				if w < 100000:
					x_num += 1
				else:
					y_num += 1
				edges += len(adj[w])
				stack.append(w)
	return x_num * y_num - (edges // 2)

ans = 0
for i in range(2*n):
	if visited[i] == False and adj[i]:
		visited[i] = True
		ans += dfs(i)
print(ans)