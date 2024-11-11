import math

def main():
	n = int(input())
	solver(n)

def solver(n):
	length = math.ceil(n**0.5)
	if length * (length - 1) >= n:
		width = length - 1
	else:
		width = length
	print(2 * (length + width))

solver(11)
solver(22)