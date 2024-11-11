n,k=map(int,input().split())
if k==1:
	print(1)
elif n%2==0:
	if k<=n//2:
		print(k+(k-1))
	else:
		print(k-(n-k))
else:
	if k<=n//2+1:
		print(k+(k-1))
	else:
		print(k-(n-k)-1)