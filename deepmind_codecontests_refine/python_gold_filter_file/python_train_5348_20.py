#!/usr/bin/env python3
# codeforces little elephant and bits

import sys

a = sys.stdin.readline().strip()

totals = {} # key = index of digit cut out, value = base 10 val of cut string
max_seen = 0
max_str = a[1:]

for i in range(len(a)):
	if a[i] == '0':
		cut = a[:i] + a[i + 1:]	
		max_str = cut
		break
	# b = int(cut, 2)
	# if b > max_seen:
	# 	max_seen = b
	# 	max_str = cut
	# totals[i] = int(cut, 2) # converts binary string to base 10

# ix = max(totals, key=lambda k: totals[k])
# print(a[:ix] + a[ix + 1:])
print(max_str)

