		

first = list(map(int,input().split()))
row = first[0]
col = first[1]
k = first[2]
graph = []
visited = []
for i in range(row):
	graph.append(list(input()))
	visited.append([False] * col)
dr = [-1,0,1,0]
dc = [0,1,0,-1]
dic = {}
for i in range(row):
	for j in range(col):
		if visited[i][j] is False and graph[i][j] == '.':
			isOk = 1
			tempt = 1
			curQueue = [[i,j]]
			q = [[i,j]]
			#print('init i= '+str(i)+" j= "+str(j))
			visited[i][j] = True
			while len(q) > 0:
				u = q.pop()
				uRow = u[0]
				uCol = u[1]
				if uRow == 0 or uRow == row - 1 or uCol == 0 or uCol== col - 1:
					isOk = 0
				for z in range(4):
					try:
						if visited[uRow + dr[z]][uCol + dc[z]] is False and graph[uRow + dr[z]][uCol + dc[z]] == '.':
							visited[uRow + dr[z]][uCol + dc[z]] = True
							#print('i= '+str(uRow + dr[z])+" j= "+str(uCol + dc[z]))
							curQueue.append([uRow + dr[z],uCol + dc[z]])
							q.append([uRow + dr[z],uCol + dc[z]])
							tempt += 1
					except Exception as e:
						continue
			if isOk == 1:
				if tempt not in dic:
					dic.setdefault(tempt, []).append(curQueue) 
					#dic[tempt].setdefault([]).append(curQueue)
				else:
					dic[tempt].append(curQueue)
count = 0
l = list(reversed(sorted(dic.keys())))
for i in l:
	q = dic[i]
	while len(q) > 0 and k != 0:
		arr = q.pop()
		k -= 1
	if k == 0:
		while len(q) > 0:
			arr = q.pop()
			for p in arr:
				r = p[0]
				c = p[1]
				graph[r][c] = '*'
				count += 1
print(count)
print("\n".join("".join(graph[i]) for i in range(row)))
				
	
	
	
	