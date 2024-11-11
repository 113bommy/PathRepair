import random, math
from copy import deepcopy as dc
from bisect import bisect_left, bisect_right
from collections import Counter


# Function to call the actual solution
def solution(li):
	ma = {}
	for i in range(len(li)):
		ma[li[i]] = ma.get(li[i], 0) + 1
	# ma1 = dc(ma)
	ans = 0
	# li = list(set(li))
	for i in range(len(li)):
		for j in range(len(li)):
			if i != j:
				f0 = li[i]
				f1 = li[j]
				if f0 == 0 and f1 == 0:
					ans = max(ans, ma[0]-2)
					continue
					
				ma[f0] -= 1
				ma[f1] -= 1
				cur = 2
				while True:
					nxt = f0 + f1
					if nxt in ma and ma[nxt] > 0:
						f0 = f1 + 1 - 1
						f1 = nxt + 1 - 1
						ma[nxt] -= 1
						cur += 1
					else:
						break
				cur1 = 2
				ma[f0] += 1
				ma[f1] += 1
				while cur1 < cur:
					prev = f1 - f0
					f1 = f0 + 1 - 1
					f0 = prev + 1 - 1
					ma[prev] += 1
					cur1 += 1
				ans = max(ans, cur)
	return ans


# Function to take input
def input_test():
		n = int(input())
		li = list(map(int, input().strip().split(" ")))
		out = solution(li)
		print(out)

# Function to test my code
def test():
	pass


input_test()
# test()