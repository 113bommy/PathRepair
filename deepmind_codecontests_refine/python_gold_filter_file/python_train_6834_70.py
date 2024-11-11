k = int(input())
if ( k <= 40 ):
	a = k%2
	b = k//2
	print 
	if int(str(8)*b + str(4)*a) < 10**18:
		print (str(8)*b + str(4)*a)
	else:
		print (-1)
else:
	print (-1)