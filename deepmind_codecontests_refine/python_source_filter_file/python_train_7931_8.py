for i in range(int(input())):
	n = int(input())
	a = sorted(list(map(int,input().split())))
	i,j=1,1
	while i<n-1:
		if a[i]-a[i-1]==1:
			j = 2
			break	
		i+=1
	print(j)