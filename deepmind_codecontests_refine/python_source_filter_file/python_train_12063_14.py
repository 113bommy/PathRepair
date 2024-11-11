import math
while t == 0:	
	try:
		x,y=[int(i) for i in input().split()]
	except:
		break
	else:
		a = int (math.log10(x + y) + 1)
		print(a)