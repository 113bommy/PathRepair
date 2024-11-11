import os
import sys
import time
import math as mt
import pprint
import itertools as it
import operator as op
import bisect as bs
import functools as fn
from collections import deque, defaultdict , OrderedDict, Counter, ChainMap
maxx, localsys, mod = 1 << 60, 0, int(1e9 + 7)
def nCr(n, r): return reduce(mul, range(n - r + 1, n + 1), 1) // factorial(r)


def ceil(n, x): return (n + x - 1) // x


osi, oso = '/home/priyanshu/Documents/cp/input.txt', '/home/priyanshu/Documents/cp/output.txt'
if os.path.exists(osi):
    sys.stdin = open(osi, 'r')
    sys.stdout = open(oso, 'w')

input = sys.stdin.readline

def maps(): return map(int, input().split())

#   THINK ABOUT THE EDGE CASES ..........

#   DON'T SUBMIT UNLESS YOU ARE ABSOLUTELY SURE !!!!!

n , m = maps()
killed = [0]*(n+1)
cnt = 0
for _ in range(m):
	u , v = maps()
	if u > v:
		v , u = u ,v
	if killed[u] == 0:
		cnt+=1
	killed[u] += 1

for _ in range(*maps()):
	s = [*maps()]
	if len(s) == 1:
		print(n - cnt)
		continue
	x , a , b = s
	if u > v :
		u , v=  v , u
	if x == 1:
		if killed[u] == 0:
			cnt+=1
		killed[u]-=1
	else:
		if killed[u] == 1:
			cnt-=1
		killed[u]-=1
#cnt --- number of people alive 