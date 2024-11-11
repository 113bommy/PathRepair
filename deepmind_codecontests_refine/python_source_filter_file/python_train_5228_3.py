q=int(input())

while q:
	
	n,k=list(map(int,input().split(" ")))
	a=n%k
	
	if n%k==0:
		print(n)

	elif k>=n:
		if k-n>=k//2:
			print(n)
		else:
			print(k//2)
#			print(n)
	#	break
	else:
		#b=k-a
		c=k//2
		num=n//k
		fin=num*k
		if a<=c:
			fina=n
		else:
			fina=fin+c
		
		
		#fina=fin+c
		print(fina)
	q=q-1



