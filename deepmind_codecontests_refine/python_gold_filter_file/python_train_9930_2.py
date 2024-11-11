n,m=map(int,input().split())
if n > m+1 or n < m:
	print("unknown topology")
	# because, we know the graph has either n or n-1 edges
	exit()
array = []
for i in range(m):
	a,b = map(int,input().split())
	array.append([a,b])
list_of_edges = [[] for _ in range(n)]
for pair in array:
	a,b = map(int, pair)
	list_of_edges[a-1].append([a,b])
	list_of_edges[b-1].append([b,a]) # because you don't know which way
if n == m: # so, either cyclic or unknown
	def traverse(list_of_edges, node, prev):
		if len(list_of_edges[node-1]) != 2:
			print("unknown topology")
			exit()
		for pair in list_of_edges[node-1]:
			if pair != [node, prev]:
				return [pair[1], pair[0]] # the successor
	num = [1,-1]
	for index in range(n):
		num = traverse(list_of_edges, num[0], num[1])
		if num[0] == 1 and index != n-1:
			print("unknown topology")
			exit()
	if num[0] == 1:
		print("ring topology")
		exit()
	else:
		print("unknown topology")
		exit()
else:
	# so here, we need to check either for the bus or the other one
	# first check for star
	leaf = 0
	is_star = True
	for i in list_of_edges:
		if len(i) not in [1, n-1]:
			is_star = False
		if len(i) == 1:
			leaf = i[0]
			leaf.reverse()
	if is_star:
		print("star topology")
		exit()
	# else it could be the bus
	def line_traverse(list_of_edges, node, prev):
		if len(list_of_edges[node-1]) not in [1,2]:
			print("unknown topology")
			exit()
		for pair in list_of_edges[node-1]:
			if pair != [node, prev]:
				return [pair[1], pair[0]] # the successor
	
	num = leaf
	for index in range(n-2):
		num = line_traverse(list_of_edges, num[0], num[1])
		if num[0] == leaf[1]:
			print("unknown topology")
			exit()
	print("bus topology")
