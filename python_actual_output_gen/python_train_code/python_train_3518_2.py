
n=int(input())
for i in range(n):
	a1,b1,n=map(int,input().split())
	a=max(a1,b1)
	b=min(a1,b1)
	t=0
	
	while a<n and b<n:
		b=b+a   
		a=a+b   
		t=t+2
	#	print(a,b)
	if n<a and n<b:
		print((t-1))
	else:
		print(t)
