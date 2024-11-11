import math
n,k=map(int,input().split())
a=list()
c=1
i=1
while i<=math.sqrt(n):
	if(n%i==0):
		if n/i==i:
			a.append(i)
			c+=1
		else:
			a.append(i)
			a.append(n/i)
			c+=2
	i+=1
a.sort()


if(len(a)<k):
	print("-1")
else:
	print(int(a[k-1]))