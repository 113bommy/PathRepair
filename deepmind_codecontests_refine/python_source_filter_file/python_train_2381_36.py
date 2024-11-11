t = 0
while t == 0:	
	try:
		a,b,e,c,d,f = [int(i) for i in input().split()]
	except:
		break
	else:
		x = (d*e - b*f) / (a*d - b*c) + 0
		y = (a*f - c*e) / (a*d - b*c) + 0
		print("{0:.3f}".format(x) + "  " + "{0:.3f}".format(y))