n,p=input().split()
n,p=int(p),int(n)
for i in range(n,p,-1):
	for j in range(2,p+1):
		if j*j>i or i%j==0:
			break
	if j==p or j*j>i:
		print(i)
		exit(0)
print(-1)