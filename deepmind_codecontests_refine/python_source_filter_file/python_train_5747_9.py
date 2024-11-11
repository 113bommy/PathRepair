from __future__ import print_function # for PyPy2
from collections import Counter, OrderedDict
from itertools import permutations as perm
from collections import deque
from sys import stdin
from bisect import *
from heapq import *
import math
 
g   = lambda : stdin.readline().strip()
gl  = lambda : g().split()
gil = lambda : [int(var) for var in gl()]
gfl = lambda : [float(var) for var in gl()]
gcl = lambda : list(g())
gbs = lambda : [int(var) for var in g()]
mod = int(1e9)+7
inf = float("inf")

n, = gil()
p = []
if n&1 == 0 :
	p.append(2)
	while n%2==0:
		n //= 2

for i in range(3, int(math.ceil(math.sqrt(n)))+1, 2):
	if n%i == 0:
		p.append(i)
		while n%i == 0:
			n //= i

	if len(p) > 1:
		break

if n > 2:
	p.append(2)

if len(p) == 1:
	print(p[0])
else :
	print(1)