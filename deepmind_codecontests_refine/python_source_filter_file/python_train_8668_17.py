from collections import defaultdict as dd
import math
import sys
import string
input=sys.stdin.readline
def nn():
	return int(input())

def li():
	return list(input())

def mi():
	return map(int, input().split())

def lm():
	return list(map(int, input().split()))


def solve():
	x,y,k=mi()

	n_sticks = k + k*y
	n_move_1 = (n_sticks-1 + x-2)//(x-1)
	n_move_2 = k
	print(n_sticks, n_move_1, n_move_2)
	print(n_move_1+n_move_2)



q=nn()

for _ in range(q):
	solve()
