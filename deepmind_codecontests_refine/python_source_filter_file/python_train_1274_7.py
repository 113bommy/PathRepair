
t = int(input())

for i in range(t):
	a =  int(input())

	x = input().split()
	sign = 0
	maxi = 0
	totsum = 0

	for j in range(a):
		y = int(x[j])

		if j == 0:
			if y > 0:
				sign = 1
			else:
				sign = -1

			maxi = y
		elif sign*y > 0:
			if y > maxi:
				maxi = y
		else:
			totsum += maxi
			maxi = y
			sign *= -1
	print(totsum) 
