r,D,x=map(int,input().split())

i=1
a=r*x-D
while i<=10:
	print(a)
    a=r*a-D
	i+=1