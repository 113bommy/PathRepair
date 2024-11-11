#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2018-03-05 15:53:55
# @Author  : Lweleth (SoungEarlf@gmail.com)
# @Link    : https://github.com/
# @Version : $Id$

n = int(input())
if n < 5:
	if n == 1 or n == 2:
		print("1\n1")
	elif n == 3:
		print("2\n1 3")
	elif n == 4:
		print("4\n2 4 1 3 ")
	exit(0)
print(n)
for i in range(1, int((n + 1) / 2)):
	print(i, i + int((n + 1)/2), end=' ')
if n % 2 == 1:
	print(int((n + 1) / 2))
else:
	print(int(n / 2), n)
