n = int(input())
str = ''
if n > 36:
	print(-1)
else:
	y = int(n/2)
	r = n%2
	#print(y)
	#print(r)
	str = '8'* y
	if r == 1:
		str += '6'
	print(str)
	
	