n,m,s,t = map(int,input().split())
dic = {}
hasEdge = []
for i in range(n):
	dic[i] = []
for i in range(n):
	hasEdge.append([])
	for j in range(n):
		hasEdge[-1].append(0)
for i in range(m):
	a,b = map(int,input().split())
	dic[a-1].append(b-1)
	dic[b-1].append(a-1)
	hasEdge[a-1][b-1] = 1
	hasEdge[b-1][a-1] = 1
distS = {}
distD = {}

def shortestDist(source,n):
	lis = []
	sol = {}
	def bfs(source):
		global dic
		nonlocal lis
		nonlocal sol
		lis.append(source)
		sol[source] = 0
		while(len(lis)!=0):
			temp = lis.pop()
			for i in dic[temp]:
				if sol.get(i)==None:
					sol[i] = sol[temp]+1
					lis.append(i)
	bfs(source)
	for i in range(n):
		if sol.get(i)==None:
			sol[i] = float("Inf")
	return sol

distS = shortestDist(s-1,n)
distD = shortestDist(t-1,n)


count = 0
for i in range(n):
	for j in range(i+1,n):
		if hasEdge[i][j]==0 and min(distS[i]+1+distD[j],distS[j]+1+distD[i])>=distS[t-1]:
			count += 1
print(count)