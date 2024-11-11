from math import sqrt
from collections import defaultdict

def roundedunitvector(vec):
	first = vec[0]
	second = vec[1]
	mag = sqrt((first * first) + (second*second))
	return (round(first/mag, 10), round(second/mag, 10))
t = int(input())
for dsklfj in range(t):
	n = int(input())
	count = 0
	d = defaultdict(lambda: 0)
	for i in range(n):
		splitted = [int(amit) for amit in input().split(" ")]
		x = splitted[0]
		y = splitted[1]
		u = splitted[2]
		v = splitted[3]
		unit = roundedunitvector((u-x, v-y))
		d[unit] += 1
		negatedUnit = (-1 * unit[0], -1 * unit[1])
		if negatedUnit in d:
			count += d[negatedUnit]
	print (count)