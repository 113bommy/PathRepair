t = int(input())
for i in range(t):
	n_m = list(map(int,input().split()))
	n = n_m[0]
	x = n_m[1]
	a = list(map(int,input().split()))
	a.sort()
	flag=0
	for j in range(n):
		if(j==0):
			diff = a[0]-1
		else:
			diff = a[j]-a[j-1]-1
		if(diff>0 and x>=diff):
			x-=diff
		elif(x==0 and diff>0):
			print(a[j-1])
			flag=1
			break
		elif(diff>0 and x<diff):
			if(j==0):
				print(x)
			else:					
				print(a[j-1]+x)
			flag=1
			break
	if(x>0 and flag==0):
		print(a[n-1]+x)
	elif(x==0 and flag==0):
		print(a[n-1])