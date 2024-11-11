n=int(input())
for i in range(1,3501):
	for j in range(1,3501):
		if 4/n-1/i-1/j==0:
			continue
		if abs((1/(4/n-1/i-1/j)-int(1/(4/n-1/i-1/j))))<10**-12:
			if (1/(4/n-1/i-1/j))>0:
				print(i,j,int(1/(4/n-1/i-1/j)))
				exit()
