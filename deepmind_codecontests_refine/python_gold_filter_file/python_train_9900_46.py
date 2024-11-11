n,k=map(int,input().split())
if 2*n-1<k :
	print(0)
elif k<=n+1 :
	if k%2:
		print(k//2)
	else:
		print(k//2-1)
else:
	t1=k-n
	if k%2==0:
		print(k//2-t1)
	else:
		print(k//2-t1+1)
