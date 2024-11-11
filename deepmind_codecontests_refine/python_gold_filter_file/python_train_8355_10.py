
t=int(input())
for i in range(t):
	
	n,x,y=map(int,input().split(" "))

	if n==2:
		print(x,y)
	else:	
		arr=[x,y]
		diff=y-x
		between=n-2+1
		while between>=1:
			if diff%between==0:
				interval=diff//between
				break
			between-=1
		for i in range(1,between):
			arr.append(x+interval*i)
		leftover=n-between-1
		for i in range(1,leftover+1):
			new=x-interval*i
			if new>0:
				arr.append(x-interval*i)
				leftover-=1
			else:
				break
		for i in range(1,leftover+1):
			arr.append(y+interval*i)

		print(*arr)