n,m=(int(i) for i in input().split())
a=[]
if(n==1 and m==1):
	print(0)
elif n==1:
	for i in range(1,m+1):
		print(i,end=' ')
	print() 
elif m==1:
	for i in range(1,n+1):
		print(i)
else:
	for i in range(n):
		a.append([0 for j in range(m)])
	for i in range(m):
		a[0][i]=(n+m)*(n+m-1-i) 
	print(*a[0])
	for i in range(1,n):
		for j in range(m):
			a[i][j]=(n+m-1-j)*(n-1-(i-1))
		print(*a[i])
