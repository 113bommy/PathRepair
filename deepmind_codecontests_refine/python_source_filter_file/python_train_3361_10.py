import sys, os
from math import sqrt, gcd, ceil, log, floor
from bisect import bisect, bisect_left
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop
input = sys.stdin.readline
read = lambda: list(map(int, input().strip().split()))
# read_f = lambda file:  list(map(int, file.readline().strip().split()))

# from time import time

# sys.setrecursionlimit(10**6)

mod = 10**9 + 7



def main():
	# file1 = open("C:\\Users\\shank\\Desktop\\Comp_Code\\input.txt", "r")
	# n = int(file1.readline().strip()); 
	# arr = list(map(int, file1.read().strip().split(" ")))
	# file1.close()
	ans = ""; MAX = 201
	for _ in range(int(input())):
		n = int(input()); arr = read(); arr.sort()

		dp = [[float("inf")]*(MAX) for i in range(n)]
		for i in range(1, MAX):dp[0][i] = min(dp[0][i-1], abs(arr[0]-i))
		# print(dp[0])
		for i in range(1, n):
			for j in range(1, MAX):
				dp[i][j] = min(dp[i][j-1], abs(arr[i]-j) + dp[i-1][j-1])

			# print(arr)
			# print(dp[i], i, arr[i])
			# print("\n")
		ans += str(min(dp[n-1]))+"\n"
	print(ans)






	# file = open("output.txt", "w")
	# file.write(ans+"\n")
	# file.close()

if __name__ == "__main__":
	main()





"""
99*98
"""