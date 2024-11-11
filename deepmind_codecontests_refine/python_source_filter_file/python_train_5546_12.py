from collections import *
from functools import *

def prod(L):
	return reduce(lambda a,b: a*b, list(L))
	

for T in range(int(input())):
	n = int(input())
	L = sorted(list(map(int, input().split())))
	pos = [x for x in L if x >= 0]
	neg = [x for x in L if x < 0]

	ret = -(1 << 28)
	if(n == 5):
		ret = max(ret, prod(L))
	if(len(pos) >= 5):
		ret = max(ret, prod(pos[-5:]))
	if(len(pos) >= 3 and len(neg) >= 2):
		ret = max(ret, prod(neg[:2])*prod(pos[-3:]))
	if(len(pos) >= 1 and len(neg) >= 4):
		ret = max(ret, prod(neg[:4])*pos[-1])
	if(len(pos) == 0 and len(neg) >= 5):
		ret = max(ret, prod(neg[-5:]))
	
	print(ret)
	
	
	