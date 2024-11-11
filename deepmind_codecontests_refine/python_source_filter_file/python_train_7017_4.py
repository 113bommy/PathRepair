import sys,math
from collections import deque
#input = sys.stdin.buffer.readline


def solve():
	n,m = map(int,input().split())
	dances = []
	edge = [[] for _ in range(n)]
	for i in range(m):
		a,b,c = map(int,input().split())
		dances.append([a-1,b-1,c-1])

		edge[a-1].append(i)
		edge[b-1].append(i)
		edge[c-1].append(i)


	visited = [False]*n
	poss = [[1,2,3] for i in range(n)]
	assign = [-1]*n

	i = 0
	q1 = deque()
	q2 = deque()
	while i<n:
		u=-1
		if len(q1)==0:
			if len(q2)==0:
				u=i
				i+=1
			else:
				u = q2.pop()
		else:
			u = q1.pop()

		if visited[u]:
			continue

		visited[u] = True
		assign[u] = poss[u][0]
		print(u,assign[u])
		for jj in range(len(edge[u])):
			j = edge[u][jj]
			for k in range(3):
				if visited[dances[j][k]]==False:
					if assign[u] in poss[dances[j][k]]:
						poss[dances[j][k]].remove(assign[u])
					if len(poss[dances[j][k]])==2:
						q2.append(dances[j][k])
					else:
						q1.append(dances[j][k])

	for i in assign:
		print(i,end=" ")
	return;


#for _ in range(int(input())):
solve()
