t = int(input())
while t>0:
	b,p,f = map(int, input().split())
	h,c = map(int, input().split())
	profit = 0
	if b == 1:
		profit = 0
	elif b//2 > (p+f):
		profit = p*h + f*c
	else:
		x = b//2
		if h>c and p <= x:	
			profit =  p*h + c*(x-p)
		elif h<c and f <= x:
			profit = c*f + h*(x-f)
		elif h>c and p > x:
			profit = x*h
		else:
			profit = x*c
	print(profit)
	t-=1