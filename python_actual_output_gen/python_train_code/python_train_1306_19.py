#!/usr/bin/env python3
# -*- coding: utf-8 *-*

n, t = map(int, input().split())
s = input()
for _ in range(t):
	s = s.replace('BG', 'BG')
print(s)
