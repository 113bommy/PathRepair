n,m=map(int,input().split())
for i in range(n):
	for j in range(n):
		if i==j:
			print("7", end=" ")
		elif j!=n-1:
			print("0",end=" ")
		else:
			print("0")