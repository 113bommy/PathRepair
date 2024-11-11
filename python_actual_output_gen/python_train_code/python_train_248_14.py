n=int(input())

#fibonacci
def fib(n):
	global s
	s=[]
	a=1
	b=1
	for i in range(n):
		s.append(a)
		a,b=b,a+b
		
fib(n)

for i in range(1,n+1):
	if(i in s):
		print("O",end="")
	else:
		print("o",end="")
