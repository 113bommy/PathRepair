for _ in range(int(input())):
	a,b,c=map(int,input().split())
	if(c==0):
		print(a)
	elif(c==1):
		print(b)
	else:
		print(a^b)