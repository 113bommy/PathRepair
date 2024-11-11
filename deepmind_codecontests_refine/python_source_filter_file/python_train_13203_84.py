import math
import sys

n = int(input())

for i in range(n):
	t,x,y = map(int, sys.stdin.readline().split())
	d = abs(x)+abs(y)

	if d < t and (d - t) % 2 == 0:
		print('No')
		exit()

print('Yes')
