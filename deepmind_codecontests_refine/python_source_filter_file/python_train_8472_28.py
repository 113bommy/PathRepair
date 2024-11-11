n,k=map(int,input().split())
if(n%2==0):
	if(k<=n//2):
		print(k+k-1)
	else:
		print((n//2-k)*2)
else:
	if(k==n//2+1):
		print(n)
	elif(k<n//2+1):
		print(k+k-1)
	else:
		print((k-(n//2+1))*2)




