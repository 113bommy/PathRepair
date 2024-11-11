t  =int(input())

for _ in range(t):
	n,x = map(int,input().split())
	adj = [[] for i in range(n+1)]
	for __ in range(1,n):
		u,v = map(int,input().split())
		adj[u].append(v)
		adj[v].append(u)

	print(adj)
	if n == 1 or n == 2 :	
		print('Ayush')
		continue
	if len(adj[x]) == 1:
		print('Ayush')
	else:
		# no of nodes odd => eg 3 -> Ayush then Ashih hamesha
		if n%2 :	print('Ashish')
		else:	print('Ayush')	

