import sys, os
# import numpy as np
from math import sqrt, gcd, ceil, log, floor
from bisect import bisect, bisect_left
from collections import defaultdict, Counter, deque
from heapq import heapify, heappush, heappop
input = sys.stdin.readline
read = lambda: list(map(int, input().strip().split()))
# read_f = lambda file:  list(map(int, file.readline().strip().split()))
# from time import time
# sys.setrecursionlimit(5*10**6)

MOD = 10**9 + 7



def main():
	# file1 = open("C:\\Users\\shank\\Desktop\\Comp_Code\\input.txt", "r")
	# n = int(file1.readline().strip()); 
	# arr = list(map(int, file1.read().strip().split(" ")))
	# file1.close()
	n, h, l, r = read()
	arr = read()
	dp = [[-1]*(h+1) for i in range(n)]

	dp[0][(arr[0]-1)%h ] = 1 if l%h <= arr[0]-1 <= r%h else 0
	dp[0][(arr[0])%h ] = 1 if l%h <= arr[0] <= r%h else 0
	

	for i in range(1, n):
		for j in range(h+1):
			if dp[i-1][j] > -1:
				if l <= (j+arr[i])%h <= r:
					dp[i][(j+arr[i])%h] = max(dp[i][(j+arr[i])%h], dp[i-1][j]+1)
				else:
					dp[i][(j+arr[i])%h] = max(dp[i][(j+arr[i])%h], dp[i-1][j])

				if l <= (j+arr[i]-1)%h <= r:
					dp[i][(j+arr[i]-1)%h] = max(dp[i][(j+arr[i]-1)%h], dp[i-1][j]+1)
				else:
					dp[i][(j+arr[i]-1)%h]  = max(dp[i][(j+arr[i]-1)%h], dp[i-1][j])

	# for i in range(len(dp)):print(i, dp[i])

	print(max(dp[n-1][l:r+1]))




	# file = open("output.txt", "w")
	# file.write(ans+"\n")
	# file.close()

if __name__ == "__main__":
	main()

"""
2 3 4 5

3 5


  1 2 3 4 5
  x x 0 0 0
  0 0 1 1 1
  x x 2 2 0






"""