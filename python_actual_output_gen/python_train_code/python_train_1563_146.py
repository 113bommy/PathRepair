t=int(input())
for i in range(t):
	n=int(input())
	if(n<=2):
		print(0)
	else:
		if(n%2==0):
			print((n//2)-1)
		else:
			print((n//2)+1)