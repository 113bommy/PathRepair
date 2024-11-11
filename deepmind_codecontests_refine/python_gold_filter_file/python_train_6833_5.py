import sys


n, k = map(int, sys.stdin.readline().strip().split())

if k == 1:
	print(n)
else:
	import math
	
	st = bin(n)[2:]

	cnt = 0
	pp = 0
	for s in st:
		if s == '1':
			cnt += 1
		pp += 1

	if pp == cnt:
		print(n)
	else:
		p = int(math.floor(math.log(n, 2))) + 1
		print(2**p - 1)