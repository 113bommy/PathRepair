n,a,b,c = [int(i) for i in input().split()]
if n%4 == 0 :
	print(0)
if n%4 == 1:
	print(min(3*a,a+b,c))
if n%4 == 2:
	print(min(2*a,b))
if n%4 == 3:
	print(min(3*a,c))
