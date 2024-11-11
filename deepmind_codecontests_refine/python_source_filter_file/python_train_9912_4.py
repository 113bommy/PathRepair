for i in range(int(input())):
	n,s=map(int,input().split())
	x=list(map(int,input().split()))
	sums=0
	fg=0
	for j in range(n):
		sums=sums+x[j]
		if(sums>=s):
			fg=1
			break

	if(fg==1):
		print(x.index(max(x[:j+1]))+1)
	else:
		print(0)