#!/usr/bin/env python3

[n, k, M, D] = map(int, input().strip().split())

def ceil(a, b):
	return -((-a) // b)

def arkkonf(x):
	return x * ceil(n // x, k)

res = 0
for d in range(1, D + 1):
	x = n // (k * d + 1)
	x = min(x, M)
	if x == 0:
		continue
	while x < M and n // x > k * D:
		x += 1
	if n // x > k * D:
		continue
	res = max(res, arkkonf(x))

print (res)
