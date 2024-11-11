
for _ in range(int(input())):
	n,x,t=map(int,input().split())
	val=min(n-1,t//x)
	if val==0:
		print(0)
	else:
		count=max(0,val*(val-1)/2+val*(n-val))
		print(int(count))
	
	

