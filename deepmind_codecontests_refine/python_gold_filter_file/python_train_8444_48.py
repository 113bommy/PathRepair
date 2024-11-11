# your code goes here
a,b,c = map(int,input().split())
if a+1<=b and a+2 <=c:
	print(3*a+3)
elif c-1 <=b and c-2<=a:
	print(3*c-3)
elif b-1<=a and b+1 <= c:
	print(3*b)