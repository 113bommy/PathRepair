#!/usr/bin/env python
import sys, math

if __name__ == '__main__':
	wtf = sys.stdin.read()
	wtf = wtf.strip().split('\n')
	#n and m (1 ≤ n, m ≤ 100)
	str = ''.join(sorted(set(''.join(wtf[1:]).replace(' ', ''))))
	tmp = ["B", "W", "BW", "BG", "BGW", "GW"]
	
	print("#Black&White" if str in tmp else "#Color")