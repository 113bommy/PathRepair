#                                               |
#   _` |  __ \    _` |   __|   _ \   __ \    _` |   _` |
#  (   |  |   |  (   |  (     (   |  |   |  (   |  (   |
# \__,_| _|  _| \__,_| \___| \___/  _|  _| \__,_| \__,_|

import sys
import math

def read_line():
	return sys.stdin.readline()[:-1]
 
def read_int():
	return int(sys.stdin.readline())
 
def read_int_line():
	return [int(v) for v in sys.stdin.readline().split()]

def kFactors(n, k): 
	  
	# list to store all prime factors of n 
	a = list() 
	  
	#insert all 2's in list 
	while n % 2 == 0: 
		a.append(2) 
		n = n // 2

	# n must be odd at this point 
	# so we skip one element(i=i+2) 
	for i in range(3, int(math.sqrt(n))+1, 2): 
		while n % i == 0: 
			n = n // i; 
			a.append(i) 

	# This is to handle when n>2 and 
	# n is prime 
	if n > 2: 
		a.append(n) 

	d = {}
	for i in a:
		if i in d:
			d[i] +=1
		else:
			d[i] = 1
	val = 1
	for i in d:
		val *= (d[i]+1)

	# if size(a)<k,k factors are not possible 
	if val != k: 
		return False
	else:
		return True

t = read_int()
for i in range(t):
	n = read_int()
	a = read_int_line()
	a.sort()
	l = 0
	r = n-1
	ans = a[l]*a[r]
	f = True

	while l<r:
		if ans!=a[l]*a[r]:
			f = False
			break
		else:
			l+=1
			r-=1

	if f and kFactors(ans,n+2):
		print(ans)
	else:
		print(-1)
