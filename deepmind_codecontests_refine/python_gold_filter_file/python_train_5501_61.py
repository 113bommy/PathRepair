n,m,k=map(int,input().split())
for nn in range(n+1):
	for mm in range(m+1):
		if nn*m+mm*n-2*mm*nn==k:
			print("Yes")
			exit()
print("No")

