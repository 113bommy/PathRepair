from collections import deque

class Graph(object):
	"""docstring for Graph"""
	def __init__(self,n,d): # Number of nodes and d is True if directed
		self.n = n
		self.graph = [[] for i in range(n)]
		self.parent = [-1 for i in range(n)]
		self.directed = d
		
	def addEdge(self,x,y):
		self.graph[x].append(y)
		if not self.directed:
			self.graph[y].append(x)

	def bfs(self, root): # NORMAL BFS
		self.parent = [-1 for i in range(self.n)]
		queue = [root]
		queue = deque(queue)
		vis = [0]*self.n
		ans = 0
		while len(queue)!=0:
			element = queue.popleft()
			vis[element] = 1
			if self.parent[element] != -1 and s[element] != -1:
				if s[self.parent[self.parent[element]]] > s[element]:
					return False
			flag = 0
			for i in self.graph[element]:
				if vis[i]==0:
					flag = 1
					queue.append(i)
					self.parent[i] = element
			# if flag == 0:
			# 	if s[element] == -1:
			# 		if parent[element] != -1:
			# 			ans+=s[parent[element]]
			# 	else:
			# 		ans+=s[element]
		return True

	def dfs(self, root, ans): # Iterative DFS
		stack=[root]
		vis=[0]*self.n
		stack2=[]
		while len(stack)!=0: # INITIAL TRAVERSAL
			element = stack.pop()
			if vis[element]:
				continue
			vis[element] = 1
			stack2.append(element)
			for i in self.graph[element]:
				if vis[i]==0:
					self.parent[i] = element
					stack.append(i)

		while len(stack2)!=0: # BACKTRACING. Modify the loop according to the question
			element = stack2.pop()
			m = 10**18
			if s[element] == -1:
				for i in self.graph[element]:
					if i!=self.parent[element]:
						m = min(m, ans[i])
				if m==10**18:
					m = 0
					ans[element] = 0
				else:
					ans[element] = m
			for i in self.graph[element]:
				if i!=self.parent[element]:
					ans[i] = max(ans[i]-ans[element],0)
		return ans

	def shortestpath(self, source, dest): # Calculate Shortest Path between two nodes
		self.bfs(source)
		path = [dest]
		while self.parent[path[-1]]!=-1:
			path.append(parent[path[-1]])
		return path[::-1]

	def ifcycle(self):
		self.bfs(0)
		queue = [0]
		vis = [0]*n
		queue = deque(queue)
		while len(queue)!=0:
			element = queue.popleft()
			vis[element] = 1
			for i in graph[element]:
				if vis[i]==1 and i!=parent[element]:
					return True
				if vis[i]==0:
					queue.append(i)
					vis[i] = 1
		return False

	def reroot(self, root, ans):
		stack = [root]
		vis = [0]*n
		while len(stack)!=0:
			e = stack[-1]
			if vis[e]:
				stack.pop()
				# Reverse_The_Change()
				continue
			vis[e] = 1
			for i in graph[e]:
				if not vis[e]:
					stack.append(i)
			if self.parent[e]==-1:
				continue
			# Change_The_Answers()



n = int(input())
g = Graph(n,False)
p = list(map(int,input().split()))
s = list(map(int,input().split()))
for i in range(len(p)):
	g.addEdge(i+1,p[i]-1)
if not g.bfs(0):
	print (-1)
	exit()
s=g.dfs(0,s)
# print (s)
print (sum(s))
