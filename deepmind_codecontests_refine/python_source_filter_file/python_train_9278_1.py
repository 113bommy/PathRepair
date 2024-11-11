x = int(input())
t  = int(x**(1/2))
if x == 1:
	print(2)
elif t**(2) == x:
	print(int(2*x**(1/2)))
elif t**2 + t < x:
	print(int(2*x**(1/2))+2)
else:
	print(int(2*x**(1/2))+1)
