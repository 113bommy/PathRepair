y =int(input())
x =0
for a in range(0,y):
	z = input()
	if z== '++x' or z== 'x++':
		x += 1
	else:
		x -=1
print(x)