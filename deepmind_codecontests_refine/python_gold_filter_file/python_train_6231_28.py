def BellmanFord(x,n,s):
	inf = float("inf")
	dist = [inf for i in range(n+1)]
	dist[s] = 0
	for i in range(1,n+1):
		for j,k,c in x:
			if j!=inf and dist[k]>dist[j]+c:
				dist[k] = dist[j]+c
				if i==n and k==n: return -1
	return dist
n,m = (int(i) for i in input().split())
x = []
for _ in range(m):
	i,j,k = (int(l) for l in input().split())
	x.append([i,j,-k])
b = BellmanFord(x,n,1)
if b==-1: print("inf")
else: print(-b[n])