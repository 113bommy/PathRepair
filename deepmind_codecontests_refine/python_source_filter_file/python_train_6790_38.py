from os import path
import sys
# mod = int(1e9 + 7)
# import re  # can use multiple splits
from math import ceil, floor,gcd,log
from collections import defaultdict , Counter
# from bisect import bisect_left, bisect_right
#popping from the end is less taxing,since you don't have to shift any elements
maxx = float('inf')

if (path.exists('input.txt')): 
	#------------------Sublime--------------------------------------#
	sys.stdin=open('input.txt','r');sys.stdout=open('output.txt','w');
	I = lambda :int(sys.stdin.buffer.readline())
	tup= lambda : map(int , sys.stdin.buffer.readline().split())
	lint = lambda :[int(x) for x in sys.stdin.buffer.readline().split()]
	S = lambda: sys.stdin.readline().replace('\n', '').strip()
	# def grid(r, c): return [lint() for i in range(r)]
	# def debug(*args, c=6): print('\033[3{}m'.format(c), *args, '\033[0m', file=sys.stderr)
	stpr = lambda x : sys.stdout.write(f'{x}' + '\n')
	star = lambda x: print(' '.join(map(str, x)))


else:
	#------------------PYPY FAst I/o--------------------------------#
	I = lambda :int(sys.stdin.buffer.readline())
	tup= lambda : map(int , sys.stdin.buffer.readline().split())
	lint = lambda :[int(x) for x in sys.stdin.buffer.readline().split()]
	S = lambda: sys.stdin.readline().replace('\n', '').strip()
	# def grid(r, c): return [lint() for i in range(r)]
	stpr = lambda x : sys.stdout.write(f'{x}' + '\n')
	star = lambda x: print(' '.join(map(str, x)))

for _ in range(I()):
	a , b = tup()
	cnt =0
	for i in range(1 , 10):
		if 10**i <= b :
			cnt+=a
	print(cnt)