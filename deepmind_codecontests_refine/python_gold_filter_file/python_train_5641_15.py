
n=int(input())
for i in range(n):
	global b
	b,f,p=map(int,input().split())
	x,y=map(int,input().split())
	sum=0
	
	def profit_p(b,p,y):
		global sum
		while b>1 and p>0:
			sum=sum+y
			p=p-1
			b=b-2
		return sum,b
	def profit_f(b,f,x):
		global sum
		while b>1 and f>0:
			sum=sum+x
			f=f-1
			b=b-2
		return sum,b
	
	if b<=1:
		print(sum)	
	else:
		if y>x:
			a1,b=(profit_p(b,p,y))
			#print(b,p,y)
			a2,b=profit_f(b,f,x)
			#print(b,f,x)
			print(a2)
		else:
			a1,b=profit_f(b,f,x)
			a2,b=profit_p(b,p,y)
			print(a2)
	#print(b,f,p,x,y)
