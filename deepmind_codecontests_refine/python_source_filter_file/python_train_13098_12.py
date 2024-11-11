from heapq import heappop,heappush
n,m,s,t = (int(i) for i in input().split())
x,y = [[] for i in range(n+1)],[[] for i in range(n+1)]
for i in range(m):
    u,v,a,b = (int(i) for i in input().split())
    x[u].append((v,a))
    x[v].append((u,a))
    y[u].append((v,b))
    y[v].append((u,b))
def dijkstra(n,s,adj):
	dis = [float("inf") for i in range(n+1)]
	dis[s],q = 0,[[0,s]]
	while q:
		num2,num = heappop(q)
		for i,j in adj[num]:
			if dis[i]>num2+j:
				dis[i] = num2+j
				heappush(q,[dis[i],i])
	return dis
X,Y,z = dijkstra(n,s,x),dijkstra(n,t,y),[]
for i in range(1,n+1): z.append((X[i]+Y[i],i))
z,k = sorted(z),0
for i in range(n):
    while z[k][1]<=i: k+=1
    print(z[k][0])