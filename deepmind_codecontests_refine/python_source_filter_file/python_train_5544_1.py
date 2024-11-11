from collections import deque 
from math import ceil
import sys

sys.setrecursionlimit(10**8) 
back_edge = []
visited = []
parent = []
level = []
def dfs(nod):
	stack = [nod]
	while stack:
		node = stack.pop()
		visited[node] =  True
		if len(back_edge)!=0:
			return
		visited[node]=True
		takenodes = []

		for i in adj[node]:
			if(visited[i] and parent[node]!=i):
				takenodes.append(i)

		if(len(takenodes)!=0):
			maximum_depth = -1
			max_node = -1
			for i in takenodes:
				if(level[i]>maximum_depth):
					maximum_depth = level[i]
					max_node = i
			back_edge.append((node,max_node))
			return


		for i in adj[node]:
			if(not visited[i]):
				parent[i]=node
				level[i] = level[node]+1
				stack.append(i)


n,m,k = map(int,input().split(" "))

adj = [[] for i in range(n+1)]
for i in range(m):
	a,b = map(int,input().split(" "))
	adj[a].append(b)
	adj[b].append(a)

if(m==n-1):
	q = deque()
	q.append(1)
	sign = [0]*(n+1)
	visited = [False]*(n+1)
	sign[1] = 0
	done = 0

	while done<n:
		curr = q.popleft()
		visited[curr] = True
		for i in adj[curr]:
			if(not visited[i]):
				q.append(i)
				sign[i] = 1 - sign[curr]
		done+=1
	l1 = []
	l0 = []

	for i in range(1,n+1):
		if(sign[i]==1):
			l0.append(i)
		else:
			l1.append(i)
	
	print(1)
	if(len(l0)>len(l1)):
		print(*l0[:ceil(k/2)])
	else:
		print(*l1[:ceil(k/2)])
else:
	parent = [0]*(n+1)
	visited = [False]*(n+1)
	level = [0]*(n+1)
	level[1] = 0
	try:
		dfs(1)
	except Exception as e:
		print(e)

	curr = back_edge[0][0]
	path = []
	while curr!=back_edge[0][1]:
		path.append(curr)
		curr = parent[curr]
	path.append(back_edge[0][1])
	if(len(path)<=k):
		print(2)
		print(len(path))
		print(*path)
	else:
		print(1)
		doned = 0
		for i in range(0,len(path),2):
			if(doned==k):
				break
			doned+=1
			print(path[i],end=" ")
		print()