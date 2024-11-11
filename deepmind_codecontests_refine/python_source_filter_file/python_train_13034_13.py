'''input
3
4
1 2 3 6
1
8
2
1 1
'''
# A coding delight
from sys import stdin
from collections import defaultdict


def give(num):
	return 0, num


# main starts
t = int(stdin.readline().strip())
for _ in range(t):
	n = int(stdin.readline().strip())
	arr = list(map(int, stdin.readline().split()))

	xor = 1
	for i in arr:
		xor ^= i

	if xor == 0:
		s = sum(arr)
		a, b = give(s)
		print(2)
		print(a, b)
	else:
		s = sum(arr) + xor
		a = xor
		b, c = give(s)
		print(3)
		print(a, b, c)