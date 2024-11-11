from os import path
import sys,time
mod = int(1e9 + 7)
from math import ceil, floor,gcd,log,log2 ,factorial,sqrt
from collections import defaultdict ,Counter , OrderedDict , deque
from itertools import combinations,permutations
# from string import ascii_lowercase ,ascii_uppercase
from bisect import *
from functools import reduce
from operator import mul
maxx = float('inf')
I = lambda :int(sys.stdin.buffer.readline())
tup= lambda : map(int , sys.stdin.buffer.readline().split())
lint = lambda :[int(x) for x in sys.stdin.buffer.readline().split()]
S = lambda: sys.stdin.readline().strip('\n')
grid = lambda  r :[lint() for i in range(r)]
stpr = lambda x : sys.stdout.write(f'{x}' + '\n')
star = lambda x: print(' '.join(map(str, x)))
localsys = 0
start_time = time.time()
#left shift --- num*(2**k) --(k - shift)
def ceill(n,x):
	return (n+x -1 )//x
nCr = lambda n, r: reduce(mul, range(n - r + 1, n + 1), 1) // factorial(r)


def solve():
	x ,y = tup()
	n = I()
	a = [x ,y , y-x , -x , -y , x- y ]
	print(a[n%6]%mod)

















def run():
	if (path.exists('input.txt')):
	    sys.stdin=open('input.txt','r')
	    sys.stdout=open('output.txt','w')

run()
solve()

if localsys:
    print("\n\nTime Elased :",time.time() - start_time,"seconds")