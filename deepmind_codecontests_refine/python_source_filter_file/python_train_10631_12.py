from os import path
import sys,time
# mod = int(1e9 + 7)
# import re
from math import ceil, floor,gcd,log,log2 ,factorial
from collections import defaultdict , Counter,deque
from itertools import permutations
# from bisect import bisect_left, bisect_right
maxx = float('inf')
#----------------------------INPUT FUNCTIONS------------------------------------------#
I = lambda :int(sys.stdin.buffer.readline())
tup= lambda : map(int , sys.stdin.buffer.readline().split())
lint = lambda :[int(x) for x in sys.stdin.buffer.readline().split()]
S = lambda: sys.stdin.readline().replace('\n', '').strip()
def grid(r, c): return [lint() for i in range(r)]
stpr = lambda x : sys.stdout.write(f'{x}' + '\n')
star = lambda x: print(' '.join(map(str, x)))
# input = sys.stdin.readline
localsys = 0
start_time = time.time()
if (path.exists('input.txt')):
	sys.stdin=open('input.txt','r');sys.stdout=open('output.txt','w');
#left shift --- num*(2**k) --(k - shift)
n = I()
ls = lint()
print(n+1)
print(2 , n , 1)
print(1 , n , 2000)
for i in range(1 , n):
	print(2 , i , 2000-i)












if localsys:
	print("\n\nTime Elased :",time.time() - start_time,"seconds")
