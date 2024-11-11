from sys import stdin
from collections import deque
mod = 10**9 + 7
import sys
# sys.setrecursionlimit(10**6)
from queue import PriorityQueue
# def rl():
#     return [int(w) for w in stdin.readline().split()]
from bisect import bisect_right
from bisect import bisect_left
from collections import defaultdict
from math import sqrt,factorial,gcd,log2,inf,ceil
# map(int,input().split())
# # l = list(map(int,input().split()))
# from itertools import permutations
import heapq
# input = lambda: sys.stdin.readline().rstrip()
input = lambda : sys.stdin.readline().rstrip()
from sys import stdin, stdout
from heapq import heapify, heappush, heappop

n = int(input())

s = input().strip()

l = [97 - (ord(i)-96) for i in s]


dp = [float("inf")]*n
ans = []

for i in l:
    posn = bisect_left(dp,i)
    print(posn)
    ans.append(posn+1)
    dp[posn] = i

print(max(ans))
print(*ans)


