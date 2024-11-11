q=int(input())
for i in range(q):
	n,a,b=map(int,input().split())
	if(n==1):
		print(a)
	elif(n%2==0):
		print(min(a*n,b/2*n))
	else:
		print(int(min(a*n,(n//2*b)+a)))