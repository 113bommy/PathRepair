import sys
import math
from bisect import bisect_left
import heapq
from collections import deque
from itertools import product, permutations
import random
def II():
	return int(sys.stdin.readline())
 
def LI():
	return list(map(int, sys.stdin.readline().split()))
 
def MI():
	return map(int, sys.stdin.readline().split())
 
def SI():
	return sys.stdin.readline().strip()
 
def C(n, k, mod):
    return (FACT(n,mod) * pow((FACT(k,mod)*FACT(n-k,mod))%mod,mod-2, mod))%mod
 
def lcm(a,b):
    return abs(a*b) // math.gcd(a, b)

x = []
xor = 0
for i in range(10**6):
	xor^=i
	x.append(xor)
 
for _ in range(II()):
	a,b = MI()
	xor = x[a-1]
	if xor == b:
		print(a)
	elif xor^b == a:
		print(a+2)
	else:
		print(a+1)