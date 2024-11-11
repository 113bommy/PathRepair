
x=int(input())
for i in range(x):
	n,a,b=map(int,input().split())
	if n==1:
		print(a)
	elif (b/2)==min(a,(b/2)):
		if n%2==0:
			print((int(n//2))*b)
		else:
			print(((int(n//2))*b)+a)
	else:
		print(n*a)


