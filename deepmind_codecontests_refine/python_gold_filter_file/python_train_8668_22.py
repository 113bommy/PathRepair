for i in range(0,int(input())):
	x,y,k=map(int,input().split())
	if (k*y+k-1)%(x-1)==0:
		print((k*y+k-1)//(x-1)+k)
	else:
		print((k*y+k-1)//(x-1)+1+k)