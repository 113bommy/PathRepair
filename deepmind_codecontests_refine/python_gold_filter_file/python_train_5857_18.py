for i in range(int(input())):
	a,b=map(int,input().split())
	if(a<=b):
		#add till a
		print((a*(a+1))//2-a+1)
	else:
		#add till b
		print((b*(b+1))//2)

