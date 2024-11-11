while True:
	n,x = map(int,input().split())
	if (n*x == 0):
		break
	sum =0
	for i in range(1,n+1):
		for j in range(i+1,n+1):
			for k in range (j+1,n+1):
				if i+j+k == x:
					sum+=1
	print(sum)


