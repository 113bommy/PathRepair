import math
n=int(input())
if 0<n<10:print(n)
elif 9<n<209:
	a=n-9
	b=str(9+math.ceil(a/2))
	print([b[0],b[1]][a%2==0])
else:
	a=n-208
	b=str(99+math.ceil(a/3)) 
	print(b[(a%3)-1])