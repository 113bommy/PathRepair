from os import path
import sys,time
# mod = int(1e9 + 7)
# import re
from math import ceil, floor,gcd,log,log2 ,factorial,cos,sin,pi
from collections import defaultdict ,Counter , OrderedDict , deque
# from itertools import combinations
from string import ascii_lowercase ,ascii_uppercase
from bisect import *
from functools import reduce
from operator import mul
maxx = float('inf')
#----------------------------INPUT FUNCTIONS------------------------------------------#
I = lambda :int(sys.stdin.buffer.readline())
tup= lambda : map(int , sys.stdin.buffer.readline().split())
lint = lambda :[int(x) for x in sys.stdin.buffer.readline().split()]
S = lambda: sys.stdin.readline().strip('\n')
grid = lambda  r :[lint() for i in range(r)]
stpr = lambda x : sys.stdout.write(f'{x}' + '\n')
star = lambda x: print(' '.join(map(str, x)))
localsys = 0
start_time = time.time()
if (path.exists('input.txt')):
	sys.stdin=open('input.txt','r');sys.stdout=open('output.txt','w');
#left shift --- num*(2**k) --(k - shift)
# input = sys.stdin.readline
n , R = tup()
theta = cos((2*pi) / n)
# a**2  = b**2  + c**2 - 2*b.c.cos A
lo = 0
hi = 100
m = maxx
d = defaultdict(int)
while  hi >= lo:
	r = lo + (hi - lo)/2
	x = (2*r)**2
	y = (1 - theta)*(2*((R+r)**2))
	if x-y == 0:
		break
	elif x - y < 0 :
		lo = r - 0.005
	else:
		hi = r  + 0.005
	d[r]+=1
	if d[r] > 1:
		break
print(r)











if localsys:
	print("\n\nTime Elased :",time.time() - start_time,"seconds")



