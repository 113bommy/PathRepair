import math

def main():
	t = int(input())
	for i in range(t):
		(a, b, c, d, k) = (int(x) for x in input().split())
		solver(a, b, c, d, k)

def solver(a, b, c, d, k):
	pens = math.ceil(a / c)
	pencils = math.ceil(b / d)
	if pens + pencils <= k:
		print(pens, pencils)
	else:
		print(-1)


