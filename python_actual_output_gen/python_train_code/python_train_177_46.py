s,v1,v2,t1,t2 =  map(int, input().split())
if (2*t1+s*v1)<(2*t2+s*v2):
	print('first')
elif (2*t1+s*v1)>(2*t2+s*v2):
	print('second')
else:
	print('friendship')
