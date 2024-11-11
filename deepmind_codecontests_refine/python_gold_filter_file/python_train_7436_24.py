n,k = map(int,input().split())
l= list(input())
j=n-1
x=0
if k==n:
	for i in range(n-1,-1,-1):
		print("PRINT",l[i])
		if i>0:
			print("LEFT\n",end='')
elif k==1:
	for i in range(n):
		print("PRINT",l[i])
		if i<n-1:
			print("RIGHT\n",end=' ')
elif k <= (n-k) :
	print("LEFT\n"*(k-1),end=' ')
	while x <= n-1:
		print("PRINT",l[x])
		if x != n-1:
			print("RIGHT")
		x+=1
elif k > (n-k):
	print("RIGHT\n"*(n-k),end='')
	while j >= 0:
		print("PRINT",l[j])
		if j != 0:
			print("LEFT")
		j-=1

