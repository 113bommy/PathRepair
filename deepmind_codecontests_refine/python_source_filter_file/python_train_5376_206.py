n=int(input())
m=int(input())
p=1
if n>=27:
	print(0)
else:
	for i in range(0,n):
		p=p*2	
	print(m%p)	