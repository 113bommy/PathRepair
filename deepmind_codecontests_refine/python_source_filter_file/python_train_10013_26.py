a=int(input())
b=int(input())
n=int(input())
if(a<b):
	c=b
	b=a
	a=c
if(n<b):
	print(n+1)
elif(n>=b) and(n<=a):
	print(b+1)
else:
	print(a-b+1)


