n,k=map(int,input().split())
a=list(map(int,input().split()))
a.sort()
s=a[0]
i=0
c=0
if a[-1]==0:
	for i in range(k):
		print(0)
else:
	while c<k:
		if i<n and a[i]!=0:
			print(a[i])
			c+=1
		if i<n-1:
			a[i+1]=a[i+1]-s
			s+=a[i+1]
		elif i>=n-1:
			print(0)
			c+=1
		i+=1

