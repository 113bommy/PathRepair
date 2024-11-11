t=int(input())
while(t>0) :
	n,k,d=[int(x) for x in input().split()]
	a=[int(x) for x in input().split()]
	maxm = n
	for i in range(0,n-d+1):
		l=len(set(a[i:i+d]))
		if l <maxm:
			maxm=l

	print(maxm)
	t-=1