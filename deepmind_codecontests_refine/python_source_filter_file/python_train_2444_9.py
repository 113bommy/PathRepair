class node():
	def __init__(self, data, adj = [], searched = 0, parent = None):
		self._data = data
		self._adj = adj
		self._searched = searched
		self._parent = parent

n, m = [int(i) for i in input().split()]
global stack
nodes = list()

def judge(node):
	global stack
	#print(len(node._adj))
	for item in node._adj:
		if item._data == node._data and item._searched == 1 and node._parent != item:
			return True
		else:
			if item._searched == 0:
				item._parent = node
				stack.append(item)
	return False

def dfs(node):
	global stack
	stack = list()
	judge(node)
	node._searched = 1
	while len(stack) > 0:
		tem = stack.pop()
		#print(tem._data)
		if tem._data == node._data:
			if(judge(tem)):
				return True
			tem._searched = 1
	return False

for i in range(n):
	tem = input()
	temp = list()
	for j in range(m):
		temp.append(node(tem[j],[]))
	nodes.append(temp)


for i in range(n):
	for j in range(m):
		if i - 1 >= 0:
			nodes[i-1][j]._adj.append(nodes[i][j])
		if i + 1 < n:
			nodes[i+1][j]._adj.append(nodes[i][j])
		if j - 1 >= 0:
			nodes[i][j-1]._adj.append(nodes[i][j])
		if j + 1 < m:
			nodes[i][j+1]._adj.append(nodes[i][j])


#for i in range(n):
#	for j in range(m):
#		print(len(nodes[i][j]._adj), i+1, j+1)

done = 0

for i in range(n):
	for j in range(m):
		if nodes[i][j]._searched == 0:
			if dfs(nodes[i][j]):
				print('Yes')
				done = 1
				break

if done == 0:
	print('No')