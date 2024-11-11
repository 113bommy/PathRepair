from collections import Counter as C,defaultdict as D,deque as Q
from operator import itemgetter as I
from itertools import product as P
from bisect import bisect_left as BL,bisect_right as BR,insort as INSORT
from heapq import heappush as HPUSH,heappop as HPOP
from math import floor as MF,ceil as MC, gcd as MG,factorial as F,sqrt as SQRT, inf as INFINITY,log as LOG
from sys import stdin, stdout
INPUT=stdin.readline
PRINT=stdout.write
L=list;M=map

def player1():
	print("")

def player2():
	print("")

def yes():
	PRINT("YES\n")

def no():
	PRINT("NO\n")

def isPrime(n):

	for i in range(2,MC(SQRT(n))+1):
		if n%i==0:
			return False
	return True

def factors(x):

	ans=[]

	for i in range(1,MC(SQRT(x))+1):
		if x%i==0:
			ans.append(i)
			if x%(x//i)==0:
				ans.append(x//i)
	return ans
def checkPath(source,destination,g):
	visited=[0]*101
	q=Q()
	q.append(source)
	visited[source]=1
	while q:
		node=q.popleft()
		if node==destination:
			return 1
		for v in g[node]:
			if not visited[v]:
				q.append(v)
				visited[v]=1
	return 0


def main():
	#for _ in range(int(INPUT())):

	n=int(INPUT())
	s=INPUT()
	round=n-11
	if s[:round].count('8')>round//2 or s[:round+1].count('8')>=round//2:
		yes()
	else:
		no()

main()

