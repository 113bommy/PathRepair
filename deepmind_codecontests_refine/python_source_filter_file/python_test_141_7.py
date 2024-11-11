from sys import stdin, setrecursionlimit, stdout
#	setrecursionlimit(100000) #use "python" instead of "pypy" to avoid MLE
from io import BytesIO
import os
from collections import deque, Counter
from math import sqrt, floor, ceil, log, log2, log10, pi, gcd, sin, cos, asin
#from heapq import heapify, heappop, heappush, heapreplace, heappushpop
#	to use maxheap, invert all the number.. that means, multyply with -1
from bisect import bisect_right, bisect_left
#	number of elements in a range is bisect_right(a, el)-bisect_left(a, el)

def ii(): return int(input().decode()) if OJ else int(input())
def fi(): return float(input().decode()) if OJ else float(input())
def mi(): return map(int, input().decode().split()) if OJ else map(int, input().split())
def fmi(): return map(float, input().decode().split()) if OJ else map(float, input().split('\n'))
def li(): return list(mi())
def si(): return input().decode().rstrip() if OJ else input().rstrip()
def lsi(): return list(si())
def oj():
	global OJ
	OJ=True
#######################################################################################
###########################    M Y     F U N C T I O N S    ###########################
#######################################################################################

def check(a, b, s):
	while max(a,b):
		x, y=a%10, b%10
		a//=10
		b//=10
		if x+y<10:
			z=s%10
			s//=10
		else:
			z=s%100
			s//=100
		if x+y!=z:
			#print('loop')
			#print(x, y, z)
			return False
	if s:
		#print('out')
		return False
	return True

def solve(a, s):
	z, zz=a, s
	ans=[]
	while s:
		x=a%10
		a//=10
		if x<=s%10:
			y=s%10
			s//=10
		else:
			y=s%100
			s//=100
		if y-x>9:
			return -1
		ans.append(y-x)
	if a:
		return -1
	p=0
	for i in ans[::-1]:
		p=p*10+i
	#print(z, p, zz)
	return p if check(z, p, zz) else -1
#######################################################################################
###########################    M A I N     P R O G R A M    ###########################
#######################################################################################

def main():
	a, s=mi()
	print(solve(a, s))


	






#######################################################################################
###########################    S T A R T E R     P A C K    ###########################
#######################################################################################

if __name__=="__main__":
	OJ=False
	#oj()

	if OJ:
		input = BytesIO(os.read(0, os.fstat(0).st_size)).readline
	else:
		input = stdin.readline


	vow={'A', 'E', 'I', 'O', 'U'}
	mod=1000000007
	res=['NO', 'YES']

	test, test_case=0, 1
	test_case=ii()
	print('>>>>>>>>>>>>> O U T P U T >>>>>>>>>>>>>\n' if not OJ else "", end="")
	while test<test_case:
		test+=1
		#print('Case #', test, ': ', sep='', end='')
		main()