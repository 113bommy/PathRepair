
import sys
from collections import deque, defaultdict
import copy
import bisect
sys.setrecursionlimit(10 ** 9)
import math
import heapq
from itertools import product, permutations,combinations
import fractions

import sys
def input():
	return sys.stdin.readline().strip()

alpha2num = lambda c: ord(c) - ord('a')


def num2alpha(num):
	if num<=26:
		return chr(96+num)
	elif num%26==0:
		return num2alpha(num//26-1)+chr(122)
	else:
		return num2alpha(num//26)+chr(96+num%26)

A = input()

loc_list = deque([])
loc_list_last = deque([])
num = 0
alpha_list = [-1] * 26
alpha_list_last = [-1] * 26
roop = 0
for i in range(len(A) - 1, -1, -1):
	alphanum = alpha2num(A[i])
	if alpha_list[alphanum] == -1:
		num += 1
		alpha_list_last[alphanum] = i
	alpha_list[alphanum] = i
	if num == 26:
		loc_list.appendleft(alpha_list)
		loc_list_last.appendleft(alpha_list_last)
		alpha_list = [-1]*26
		alpha_list_last = [-1]*26
		roop += 1
		num = 0
loc_list.appendleft(alpha_list)
loc_list_last.appendleft(alpha_list_last)
ans = deque([])
#print(loc_list)
for i in range(26):
	if loc_list[0][i] == -1:
		x = i
		ans.append(x)
		break

if len(loc_list) > 1:
	mozi = x
	for n in range(1, len(loc_list)):
		loc = loc_list[n][mozi]
		#print(loc, mozi)
		for i in range(26):
			if loc_list_last[n][i] <= loc:
				ans.appendleft(i)
				mozi = i
				break
#print(loc_list)

ans2 = []

for i in range(len(ans)):
	ans2.append(num2alpha(ans[i] + 1))
print(''.join(ans2))