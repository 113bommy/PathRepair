from os import path
import sys,time
# mod = int(1e9 + 7)
# import re
from math import ceil, floor,gcd,log,log2 ,factorial
from collections import defaultdict ,Counter , OrderedDict , deque
# from itertools import combinations
# from string import ascii_lowercase ,ascii_uppercase
# from bisect import *
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

n = I()
ls = lint()
d = defaultdict(int)
for i in ls:
	d[i]+=1
f , t =0, 0
for i in d:
	f+=d[i]//4
	t+=d[i]//2
for _ in range(I()):
	op , x = S().split()
	x =int(x)
	f-=d[x]//4
	t-=d[x]//2
	if op =='+':
		d[x]+=1
	else:
		d[x]-=1
	f+=d[x]//4
	t+=d[x]//2
	print('YES') if f + t >= 5 else print('NO')















if localsys:
	print("\n\nTime Elased :",time.time() - start_time,"seconds")


