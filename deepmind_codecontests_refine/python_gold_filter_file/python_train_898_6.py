#!/usr/bin/env python3

import sys

n = int(sys.stdin.readline().strip())
chs = [sys.stdin.readline().strip() for _ in range(n)]

soft = sum(ch.endswith('soft') for ch in chs)
hard = sum(ch.endswith('hard') for ch in chs)

for i in range(1, 16):
	b = i**2 // 2
	w = (i**2 + 1) // 2
	if (b >= min(soft, hard)) and (w >= max(soft, hard)):
		print (i)
		break