from math import ceil
from collections import deque

for _ in range(int(input())):
	n, x, y = [int(i) for i in input().split()]
	a = []
	j = 1
	while j <= y-x:
		if (y-x)%j == 0:
			a.append(j)
		j += 1

	d = y-x
	for i in a:
		if n > (y-x)//i:
			d = i
			break

	mn = max(x%d, x%d-d*(n-(y-x)//i-1), y-d*(n-1))
	for i in range(n):
		print(mn, end=' ')
		mn += d
	print()