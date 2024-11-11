n,k = map(int,input().split())
r = 0
for i in range(n):
	t = input()
	visited = [False]*(k+1)

	for i in t:
		if int(i) > k:
			continue
		else:
			visited[int(i)] = True
	if True in visited:
		if visited.count(True) == k+1:
			r = r + 1
print(r)