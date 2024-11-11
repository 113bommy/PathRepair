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


# https://codeforces.com/blog/entry/46681
def solve():
	n, = aj()
	if n <= 2:
		print(-1)
	elif n%2:
		k = (n**2 + 1)//2
		m = (n**2 - 1)//2
		print(k,m)
	else:
		k = (n**2 + 4)//4
		m = (n**2 - 4)//4
		print(k,m)
	

try:
	#os.system("online_judge.py")
	sys.stdin = open('input.txt', 'r') 
	sys.stdout = open('output.txt', 'w')
except:
	pass

solve()