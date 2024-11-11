# rambo_1

from math import *
from copy import *
from string import *				# alpha = ascii_lowercase
from sys import stdin
from sys import maxsize
from operator import *				# d = sorted(d.items(), key=itemgetter(1))
from itertools import *
from collections import Counter		# d = dict(Counter(l))
from collections import defaultdict # d = defaultdict(list)

'''
4
onetwone
testme
oneoneone
twotwo


onetwonetwooneooonetwooo
'''

def solve(s):
	n = len(s)
	l = list(s)
	one = s.count('one')
	two = s.count('two')
	total = one + two
	llen = total*3
	if(total == 0):
		print(0)
		print()
	else:
		i,ans = 0,0
		L = []
		s += 'zzzzz'
		l = list(s)
		while(i < n):
			curr = ''.join(l[i:i+6])
			# print("curr:",''.join(curr),len(curr),i)
			if(curr == 'onetwo'):
				l[i+1] = 'z'
				L.append(i+1)
				i += 1
				ans += 1
			elif(curr == 'oneone'):
				l[i+1] = 'z'
				L.append(i+1)
				i += 1
				ans += 1
			elif(curr == 'twotwo'):
				l[i+1] = 'z'
				# print("@")
				L.append(i+1)
				i += 1
				ans += 1
			elif(l[i:i+5] == list('twone')):
				# print("*",i)
				l[i+2] = 'z'
				L.append(i+2)
				i += 1
				ans += 1
			elif(curr == 'onezzz'):
				l[i+1] = 'z'
				L.append(i+1)
				i += 1
				ans += 1
			elif(curr == 'twozzz'):
				l[i+1] = 'z'
				# print("yeee")
				i += 1
				L.append(i+1)
				ans += 1
			elif(l[i:i+3] == list('two')):
				l[i+1] = 'z'
				L.append(i+1)
				i += 1
				ans += 1
			elif(l[i:i+3] == list('one')):
				l[i+1] = 'z'
				L.append(i+1)
				i += 1
				ans += 1
			else:
				i += 1
			# print("l:",''.join(l))
		# print("*",''.join(l))
		print(ans)
		print(*L)

T = int(input())
for _ in range(T):
	s = input()
	solve(s)

