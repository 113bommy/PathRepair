#!/usr/bin/env python
import sys, math

if __name__ == '__main__':
	wtf = sys.stdin.read()
	wtf = wtf.strip().split('\n')
	#t (1≤t≤1000)
	T = int(wtf[0])
	assert T >= 1 and T <= 1000, "Precondition failure"
	for t in wtf[1:]:
		n = int(t)
		print(n if n == 1 else round(n/2))