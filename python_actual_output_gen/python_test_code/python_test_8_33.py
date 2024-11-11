for i in range(int(input())):
	x=0
	e=0
	s,a,b,c=map(int,input().split())
	x=s//c
	e=x*b//a
	print(x+e)