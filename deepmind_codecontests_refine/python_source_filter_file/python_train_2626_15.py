for _ in range(int(input())):
	n,p,k=map(int,input().split());a=sorted(map(int,input().split()));c=[0]*n;x=0
	for i in range(n):
		c[i]=c[(i-1 if i<k-1 else i-k)]+a[i]
	for i in range(n):
		if a[i]<=p:ans=i+1
	print(ans)