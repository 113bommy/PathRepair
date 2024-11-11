import math

def Core(data):
	data = [int(el) for el in data.split(" ")]
	if data[1] % 2 == 0:
		print (math.ceil(data[0]/2 - data[1]/2 + 1))
	else:
		print (math.ceil(data[1]/2))
Core(input())