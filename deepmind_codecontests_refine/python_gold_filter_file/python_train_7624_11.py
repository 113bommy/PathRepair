n=int(input())
for i in range(n):
	x,y=map(int,input().split())
	if y > x:
		x,y  = y,x
	z = max(2*y,x)
	print(z**2)