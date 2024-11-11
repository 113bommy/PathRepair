[n,k]=map(int, input().split())
if n%k==0:
	print(n+k)
else:
	print((k*(n//k)+1))