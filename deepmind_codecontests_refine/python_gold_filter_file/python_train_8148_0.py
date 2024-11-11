import io,os
from math import *

n = int(input())
a = sorted([int(x) for x in input().split()])

def solve(l, bit):
	if len(l) <= 1:
		return 0
	if bit == 0:
		return 0
	high = [x ^ (1 << bit) for x in l if x & (1 << bit)]
	low = [x for x in l if not x & (1 << bit)]
	sh = solve(high, bit-1)
	sl = solve(low, bit-1)
	if not low:
		return sh
	if not high:
		return sl
	return min(len(high) - 1 + sl, len(low) - 1 + sh)

print(solve(a, 40))
