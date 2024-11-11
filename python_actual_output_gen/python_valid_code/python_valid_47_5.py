n,k = map(int,input().split())
if n == 9 and k ==1:
	print(9,10)
else:
	if k-n>1 or k-n<0:
		print(-1)
	else:
		if n==k:
			if n==0:
				print(-1)
			else:
				print(n*10,n*10+1)
		else:
			print(n*10+9,n*20)