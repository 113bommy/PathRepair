n,k=map(int,input().split())
i=r=0
for j,a in enumerate(map(int,input().split())):
	if a > n-k:
		r=r*(j-i)%998244353 or 1
		i=j
print(int((2*n-k+1)*k/2), r%998244353)