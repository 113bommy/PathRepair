s,v1,v2,t1,t2 = map(int, input().split())
r1 =  2*t1 + s*v1
r2 = 2*t2 +s*v2
if  r1> r2:
	print('First')
elif r1 == r2:
	print('Friendship')
else:
	print('Second')