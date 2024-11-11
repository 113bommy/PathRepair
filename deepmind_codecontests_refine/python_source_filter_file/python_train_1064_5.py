n = int(input())
order = []
# mat = [[] for i in range(n)]
adj = [[] for i in range(n)]

# for i in range(n):
# 	mat[i] = [-2]*n
# print(mat)
tel = {}
for i in range(n-1):
	a,b =  [int(s)-1 for s in input().split()]
	order.append((a,b))
	tel[(a,b)] = -1
	tel[(b,a)] = -1
	# mat[a][b] = -1
	# mat[b][a] = -1
	adj[a].append(b)
	adj[b].append(a)
print(tel)
count = 0
for i in range(n):
	if len(adj[i])>=3:
		for j in adj[i]:
			if tel[(i,j)] == -1:
				tel[(i,j)] = count
				tel[(j,i)] = count
				# mat[i][j] = count
				# mat[j][i]  = count
				count+=1
for i in range(n):
	if len(adj[i])<3:
		for j in adj[i]:
			if tel[(i,j)] == -1:
				tel[(i,j)] = count
				tel[(j,i)] = count
				# mat[i][j] = count
				# mat[j][i] = count
				count+=1
for i in range(n-1):
	print(tel[(order[i][0],order[i][1])])
	# print(len(adj[i]))
# print(mat)

