a,b=map(int,input().split())

x=a%b

while x>0:
	a=b
	x=a%x
	b=x

print(a)
