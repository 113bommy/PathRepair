n,m,k=map(int,input().split())
for nn in range(n):
	for mm in range(m):
		if nn*m+mm*n-2*mm*nn==k:
			print("Yes")
			exit()
print("No")

