import math

sum = int(input())

fours = 1000000
sevens = 1000000
found = 0

for i in range(int(sum/4)):
	"""
	   4x + 7y = sum 
	   ( sum - 4x ) / 7 = y
	"""
	y = (sum - 4*i) / 7
	if (y - math.floor(y) == 0):
		if ((i + y < fours + sevens) or (i + y == fours + sevens and i > fours)):
			found = 1
			fours = i
			sevens = y

if found == 0:
	print(-1)
	exit()

while fours != 0:
	print(4, end = '')
	fours = fours - 1

while sevens != 0:
	print(7, end = '')
	sevens = sevens - 1