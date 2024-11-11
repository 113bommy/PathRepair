def GCD(a, b):
	if b > a:
		return GCD(b, a)
	elif a % b == 0:
		return b
	return GCD(b, a % b)
		
def LCM(a, b):
	return a * b / GCD(a, b)

import sys
L = sys.stdin.readlines()
for line in L:
	x, y = list(map(int, line.split()))
	print(GCD(x, y), LCM(x, y))