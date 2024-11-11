import math
import sys
from collections import Counter

n = sys.stdin.readline().rstrip()
l = sys.stdin.readline().rstrip()
l = [int(x) for x in l.split(' ')]
if len(l) == 2:
	print(l[0])
else:
	a = l[0]
	b = l[1]
	aa = a % 2
	bb = b % 2
	if aa == bb:
		i = 2
		while l[i] % 2 == aa:
			i += 1
		print(i)
	else:
		if l[2] % 2 == aa:
			print(1)
		else:
			print(0)