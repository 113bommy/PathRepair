from collections import defaultdict
n = int(input())

d = defaultdict(list)

def DFSop(d1,x,goal,state,visited):

	
	c = 0
	stack = [(x,c)]
	l = []
	while len(stack):

		temp,c = stack.pop()
		visited[temp] = 1
		if c%2 == 1:
			state[temp-1] = 1 - state[temp-1]
		if state[temp-1] != goal[temp-1]:
			c = c + 1
			state[temp-1] = goal[temp-1]
			l.append(temp)
		for i in d1[temp]:

			if visited[i] == 0:
				stack.append((i,c))
	return l

# def DFSop(d1,x,goal,state,c,visited,l):

# 	if c%2 == 1:
# 		state[x-1] = 1-state[x-1]
# 	elif c%2 == 0:
# 		state[x-1] = state[x-1]
# 	if goal[x-1] != state[x-1]:
# 		state[x-1] = goal[x-1]
# 		count = 1
# 		c = c + 1
# 		l.append(x)
# 	else:
# 		count = 0
# 	visited[x] = 1
# 	for i in d1[x]:

# 		if visited[i] == 0:
# 			DFSop(d1,i,goal,state,c,visited,l)
# 	return l

def DFS(d,x,parent,visited):

	stack = [(x,0)]
	d1 = defaultdict(list)

	while len(stack):

		temp,parent = stack.pop()
		visited[temp] = 1
		# print(temp,parent)
		for i in d[temp]:

			if visited[i] == 0:
				d1[parent].append(i)
				stack.append((i,temp))

	return d1
for i in range(n-1):

	a,b = map(int,input().split())
	d[a].append(b)
	d[b].append(a)
parent = 0

visited = [0 for i in range(n+1)]


x = 1

state = list(map(int,input().split()))
goal = list(map(int,input().split()))
c = 0
x = 1
parent = 0
d1 = DFS(d,x,parent,visited)

visited = [0 for i in range(n+1)]
l = []
ans = DFSop(d1,x,goal,state,visited)


for i in d[1]:


	ans = ans + DFSop(d1,x,goal,state,visited)
ans = set(ans)
print(len(ans))
for i in ans:
	print(i)
