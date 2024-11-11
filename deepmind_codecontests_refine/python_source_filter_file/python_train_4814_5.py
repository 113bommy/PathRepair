t=int(input())
for tt in range(t):
	nx = input().split()
	n = int(nx[0])
	x = int(nx[1])
	lis = input().split()
	for i in range(n):
		lis[i] = int(lis[i])
	lis.sort()
	ind = -1
	for i in range(n):
		if(lis[i]>=x):
			ind = i
			break
	if(ind==-1):
		print(0)
	else:
		dist = 0
		for i in range(ind,n):
			dist += lis[i] - x
		ans = n - ind
		# while dist>0:
		for i in range(ind-1,-1,-1):
			# print("Mid dist",dist)
			if(x - lis[i-1] <= dist):
				ans+=1
				dist -= x - lis[i-1]
			else:
				break
		print(ans)


