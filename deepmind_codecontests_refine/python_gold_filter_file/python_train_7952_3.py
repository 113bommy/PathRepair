n,m=[int(x) for x in input().split()]
forbidden=set()
for i in range(m):
	a,b=[int(x) for x in input().split()]
	forbidden.add(a)
	forbidden.add(b)
for i in range(1,n+1):
	if i not in forbidden:
		print(n-1)
		for j in range(1,n+1):
			if j!=i:
				print(j,i)
		exit()