#!/usr/bin/env python3

n = int(input())
m = [int(x) for x in input().split()]
r = [int(x) for x in input().split()]

counter = 0
num = 50000

for d in range(num):
	for i in range(n):
		if d % m[i] == r[i]:
			counter += 1
			break

frac = counter/num
print(frac)
