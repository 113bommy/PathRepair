while(True):
	a,b=list(map(int,input().split()))
	if a==0 and b==0:
		break
	c=0
	for i in range(a):
		for j in range(i):
			for k in range(j):
				if i+j+k==b:
					c+=1
	print(c)