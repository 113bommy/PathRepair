#! /usr/bin/python3

n, d, m = [int(inp) for inp in input().split()]
aArr = sorted([int(inp) for inp in input().split()], reverse = True)

i = sum([j > 0 for j in aArr])

aU = aArr[:i]
aL = aArr[i:]

aUS = aU
for i in range(1, len(aU)):
	aUS[i] += aUS[i - 1]
aUS = [0] + aUS

aLS = aL
for i in range(1, len(aL)):
	aLS[i] += aLS[i - 1]
aLS = [0] + aLS

fromU = min(1 + (n - 1)//(d + 1), len(aU))

maxFun = aUS[0] + aLS[-1]

for j in range(1, fromU + 1):
	newFun = aUS[j] + aLS[min(max(0, n - 1 - (j - 1)*(d + 1)), len(aL))]
	if newFun > maxFun:
		maxFun = newFun

print(maxFun)