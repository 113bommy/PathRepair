#!/usr/bin/env python3
from sys import stdin
p, q, l, r = map(int, stdin.readline().split())

z_list = []
x_list = []
for x in range(p):
	i, j = map(int, stdin.readline().split())
	for x in range(i, j+1):
		z_list.append(x)
for x in range(q):
	i, j = map(int, stdin.readline().split())
	for x in range(i, j+1):
		x_list.append(x)

t = l
ans = 0
for x in range(l, r+1):
	xt_list = [x+t for x in x_list]
	t += 1
	if len(list(set(z_list) & set(xt_list))) != 0:
		ans += 1

print(ans)