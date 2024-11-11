#!/usr/bin/python3

# Codeforces - Round #683
# Author: frostD
# Problem A - Add Candies


def read_int():
	n = int(input())
	return n


def read_ints():
	ints = [int(x) for x in input().split(" ")]
	return ints
	

#---

def solve(n):
	sol = []
	sol.append(n)
	sol.append(list(range(1, n+1)))
	return sol


# Main
t = read_int()
for case in range(t):
	n = read_int()
	sol = solve(n)
	print (sol[0])
	print (' '.join([str(x) for x in sol[1]]))
