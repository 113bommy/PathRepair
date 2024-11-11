for _ in range(int(input())):
	s,a,b,c=map(int,input().split())
	print((s*b)//(a*c)+(s//c))