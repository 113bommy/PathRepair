'''input
9 4 8
6 8 5 1 8 1 1 2 1
9 2
8 4
5 3
9 7
'''
from sys import stdin
import math
from copy import deepcopy
from collections import defaultdict


def process_offer(offers):
	aux = []
	for i in offers:
		temp = offers[i]
		temp.sort()
		aux.append([i, temp[-1]])

	aux = sorted(aux, key = lambda x: x[0])
	return aux


def make(first, second):
	return str(first) + ' ' + str(second)


def brute(arr, dp, offers, index, remain):
	print(index, remain)
	# base case:
	if remain == 0:
		return 0

	if make(index, remain) in dp:
		return dp[make(index, remain)]

	min_cost = arr[index] + brute(arr, dp, offers, index + 1, remain - 1)
	#print(min_cost)
	for i in range(len(offers)):
		cost = 0
		if offers[i][0] <= remain:
			free = offers[i][1]
			for  j in range(index + free, index + offers[i][0]):
				cost += arr[j]
			cost += brute(arr, dp, offers, index + offers[i][0], remain - offers[i][0])
			min_cost = min(min_cost, cost)
		else:
			break
	dp[make(index, remain)] = min_cost
	return min_cost



# main starts
n, m, k = list(map(int, stdin.readline().split()))
arr = list(map(int, stdin.readline().split()))
arr.sort()
offers = defaultdict(list)
for _ in range(m):
	x, y = list(map(int, stdin.readline().split()))
	offers[x].append(y)

offers = process_offer(offers)
dp = dict()
print(brute(arr, dp, offers, 0, k))
#print(dp)

