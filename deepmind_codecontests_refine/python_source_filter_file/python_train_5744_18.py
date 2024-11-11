def data(a):
	da=0
	while a != 0:
		da=da+a%10
		a=int(a/10)
	# print(da)
	return da

a=int(input())
if(data(a)%4==0):
	print(a)
else:
	for x in range(a,1000):
		if(data(x)%4==0):
			print(x)
			break
	# data(x)

