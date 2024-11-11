t=int(input())
for i in range(t):
	n=int(input())
	if n%2==0:
		print(2,n-3,1)
	elif (n-1)//2%3==0:
		print((n-1)//2-1,(n-1)//2+1, 1)
	else:
		print((n-1)//2-2,(n-1)//2+2,1)