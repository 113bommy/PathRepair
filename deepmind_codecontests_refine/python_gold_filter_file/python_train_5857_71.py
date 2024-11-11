for _ in range(int(input())):
	n,r=map(int,input().split())
	if(r>=n):
		print((n*(n-1)//2)+1)
	else:
		print((r*(r+1))//2)