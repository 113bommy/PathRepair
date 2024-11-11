#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Dec 21 18:17:38 2019

@author: puchisspanitpotjaman
"""
data = input()
a = [int(n) for n in data.split()]
opt = 0
opt_n = 0
opt_k = 0
opt_l = 0
if a[0] <= 2*a[1] + 1:
	print(1)
	print(a[0]//2+1)
elif a[0] < 4*a[1] + 2 and a[0] > 2*a[1] + 1:
	print(2)
	if a[0]%2 == 1:
		opt = a[0]//2
		opt_n = opt - a[1]
		opt_k = opt + 1
		opt_l = opt_k - a[1]
		print(opt_n,a[0]-opt_l+1)
	if a[0]%2 == 0:
		opt = a[0]//2
		opt_n = opt - a[1]
		print(opt_n,a[0]-opt_n+1)
else:
	i = a[0]
	col = 0
	while i > 4*a[1]+2:
		i -= 2*a[1]+1
		col += 1
	print(col+2)
	if i%2 == 1:
		opt = i//2
		opt_n = opt - a[1]
		opt_k = opt + 1
		opt_l = opt_k - a[1]
		print(opt_n, end =" ")
		l = opt_n
		for k in range(col):
			l += 2*a[1]+1
			print(l, end =" ")
		print(a[0]-opt_l+1)
	
	else:
		opt = i//2
		opt_n = opt - a[1]
		l = opt_n
		print(opt_n, end =" ")
		l = opt_n
		for k in range(col):
			l += 2*a[1]+1
			print(l, end =" ")
		print(a[0]-opt_n+1)
