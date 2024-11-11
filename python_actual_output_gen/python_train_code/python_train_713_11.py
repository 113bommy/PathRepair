#!/usr/bin/env python3

n, m, k = map(int, input().split(' '))

if k < n:
	print(1, k + 1)
else:
	k -= n
	m -= 1
	row = n - k//m

	k %= m

	if row % 2 == 0:
		print(row, 2 + k)
	else:
		print(row, 1 + (m -k))
