n=int(input())
cst=list(map(int,input().split()))
route=list(map(int,input().split()))
visited=[0]*n
cost=0
for i in range(n-1):
	if visited[i]==0:
		mini=99999999
		j=i
		while(visited[j]==0):
			visited[j]=i+1
			j=route[j]-1
			#print(visited,j)
			if visited[j]==i+1:
				mini=cst[j]
				k=route[j]-1
				while(k!=j):
					#print(k,j)
					if cst[k]<mini:
						mini=cst[k]
					k=route[k]-1
		if mini!=99999999:
			cost+=mini
print(cost)
