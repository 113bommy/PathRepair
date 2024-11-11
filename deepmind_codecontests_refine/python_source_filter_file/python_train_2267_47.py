n,k = map(int,input().split())
a = list(map(int,input().split()))
for i in range(n+1):
	for x in [1,-1]:
		y = n + x*i
		if y not in a:
			print(y)
			exit(0)