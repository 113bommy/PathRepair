from collections import Counter as C,defaultdict as D,deque as Q
from operator import itemgetter as I
from itertools import product as P
from bisect import bisect_left as BL,bisect_right as BR
from heapq import heappush as HPUSH,heappop as HPOP
from math import floor as MF,ceil as MC, gcd as MG,factorial as F,sqrt as SQRT, inf as INFINITY


def player1():
	print("")

def player2():
	print("")

def isPrime(n):

	for i in range(2,MC(SQRT(n))+1):
		if n%i==0:
			return False
	return True


def main():


	for _ in range(int(input())):

		n=int(input())

		p=list(map(int,input().split( )))
		ans=[]
		ans.append(p[0])
		if p[1]>p[0]:
			ans.append(p[1])
		else:
			ans.append(-p[1])

		for i in range(2,n):

			if p[i]>abs(ans[-1]):
				ans.append(-abs(ans[-1]))
				ans.append(p[i])
			else:
				ans.append(abs(ans[-1]))
				ans.append(-p[i])
		
		res=[ans[0]]
		for i in range(1,len(ans)-1,2):
			if ans[i]!=-ans[i+1]:
				res.append(ans[i])

		res.append(abs(ans[-1]))
		print(len(res))
		print(*res)






main()
