# ANSHUL GAUTAM
# IIIT-D

from math import *
from copy import *					# ll = deepcopy(l)
from heapq import *					# heappush(hp,x)
from string import *				# alpha = ascii_lowercase
from random import *				# l.sort(key=lambda l1:l1[0]-l1[1]) => ex: sort on the basis difference
from bisect import *				# bisect_left(arr,x,start,end)  => start and end parameters are temporary
from sys import stdin				# bisect_left return leftmost position where x should be inserted to keep sorted
from sys import maxsize				# minn = -maxsize
from operator import *				# d = sorted(d.items(), key=itemgetter(1))
from itertools import *				# pre = [0] + list(accumulate(l))
from decimal import Decimal 		# a = Decimal(a)	# use this for math questions
from collections import Counter		# d = dict(Counter(l))
from collections import defaultdict # d = defaultdict(list)

'''
4
4
3 2 7 6
3
3 2 6
1
7
7
4 9 2 1 18 3 0
'''

def solve(s,k):
	n = len(s)
	# print('s:',s)
	if(n == 1):
		return 1
	ind = []
	for i in range(n):
		if(s[i] == '1'):
			ind.append(i)
	# ind.append(n)
	if(s.count('1') == 0):
		ans = 0
		for i in range(0,n,k+1):
			ans += 1
		return ans
	# print(ind)
	first = s.find('1') - k
	last = n - s.rfind('1') - k - 1
	add = max(0,ceil(first/(k+1)))
	# print(add)
	add += max(0,ceil(last/(k+1)))
	# print(add)
	for i in range(1,len(ind)):
		diff = ind[i] - ind[i-1] - 1 - 2*k
		# print('->',diff,max(0,floor(diff/k)))
		add += max(0,ceil(diff/(k+1)))
	return add
	

T = int(input())
for _ in range(T):
	N,K = list(map(int, stdin.readline().rstrip().split()))
	l = input()
	print(solve(l,K))

