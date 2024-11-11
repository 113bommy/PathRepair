
from sys import stdin,stdout,setrecursionlimit
stdin.readline
def mp(): return list(map(int, stdin.readline().strip().split()))
def it():return int(stdin.readline().strip())
from collections import defaultdict as dd,Counter as C,deque
from math import ceil,gcd,sqrt,factorial,log2,floor	
from bisect import bisect_right as br,bisect_left as bl
import heapq

def solve():
	n = it()
	l = mp()
	if n == 1:
		if l[0]>=0:
			print(l[0])
		else:
			print(abs(l[0])-1)
	elif not n&1:
		for i in range(n):
			if abs(l[i]) != l[i]:
				print(l[i] , end=" ")
			else:
				print(-l[i]-1 , end=' ')
	else:
		mx = -(1<<60)
		for i in range(n):
			if abs(l[i]) == l[i]:
				if l[i]>mx:
					mx = max(mx,l[i])
					indx = i
			else:
				if abs(l[i])-1>mx:
					mx = max(mx,abs(l[i])-1)
					indx = i
		flag = 0
		for i in range(n):
			if i == indx and not flag:
				print(mx,end=' ')
				flag = 1
			elif abs(l[i]) != l[i]:
				print(l[i],end=' ')
			else:
				print(-l[i]-1 , end=' ')

solve()



