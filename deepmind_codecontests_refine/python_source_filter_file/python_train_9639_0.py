x,y = [int(z) for z in input().split()]
n = 1
if x//2>0 and y//24 >0 :
	n = min(x//2,y//24)
	x -= 2 * n
	y -= 24 * n
	if (n%2 == 0):
		n += 1
while(True):
	#print (n,x,y)
	if n%2 :
		if y < 2:
			print('Hanako')
			break
		y -= 2
		if x < 2:
			tmp = (200 - x*100)//10
			if y < tmp :
				print('Hanako')
				break
			else:
				y -= tmp
				x = 0
		else:
			x -= 2
	#	print('c',x,y)
	else:
		if y < 2:
			print('Ciel')
			break
		if y < 22 :
			y -= 2
			tmp = (y * 10)//100
			y -= (tmp *100)//10
			if x < tmp :
				print('Ciel')
				break
			else:
				if x < (2 - tmp):
					print('Ceil')
					break
				x -= (2 - tmp)
		else:
			y -= 22
	#	print ('h',x,y)
	n += 1
