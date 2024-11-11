import math,sys,bisect,heapq,os
from collections import defaultdict,Counter,deque
from itertools import groupby,accumulate
from functools import lru_cache
#sys.setrecursionlimit(200000000)
int1 = lambda x: int(x) - 1
def input(): return sys.stdin.readline().rstrip('\r\n')
#input = iter(sys.stdin.buffer.read().decode().splitlines()).__next__
aj = lambda: list(map(int, input().split()))
def list3d(a, b, c, d): return [[[d] * c for j in range(b)] for i in range(a)]
#MOD = 1000000000 + 7
def Y(c):  print(["NO","YES"][c])
def y(c):  print(["no","yes"][c])
def Yy(c):  print(["No","Yes"][c])

def solve():
	n, = aj()
	A = []
	for i in range(n):
		a = aj()
		A.append(a)

	if n == 1:
		print(1)
		exit(0)

	s = None;empty = None
	for i in A:
		t = sum(i)
		if 0 not in i:
			if s == None:
				s = t
			elif s !=  t:
				print(-1)
				exit(0)
		else:
			if empty == None:
				empty = t
			elif empty != t:
				print(-1)
				exit(0)
	B = list(zip(*A))
	for i in B:
		t = sum(i)
		if 0 not in i:
			if s == None:
				s = t
			elif s !=  t:
				print(-1)
				exit(0)
		else:
			if empty == None:
				empty = t
			elif empty != t:
				print(-1)
				exit(0)
	t1,t2 = [],[]
	for i in range(n):
		t1.append(A[i][i])
		t2.append(A[i][n-i-1])
	if 0 in t1:
		if sum(t1) != empty:
			print(-1)
			exit(0)
	else:
		if sum(t1) != s:
			print(-1)
			exit(0)
	if 0 in t2:
		if sum(t2) != empty:
			print(-1)
			exit(0)
	else:
		if sum(t2) != s:
			print(-1)
			exit(0)
	ans = s - empty
	if ans == 0:
		print(-1)
	else:
		print(ans)






		

















try:
	#os.system("online_judge.py")
	sys.stdin = open('input.txt', 'r') 
	sys.stdout = open('output.txt', 'w')
except:
	pass

solve()