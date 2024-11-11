#: Author - Soumya Saurav
import sys,io,os,time
from collections import defaultdict
from collections import OrderedDict
from collections import deque
from itertools import combinations
from itertools import permutations
import bisect,math,heapq
alphabet = "abcdefghijklmnopqrstuvwxyz"

input = sys.stdin.readline

########################################

n = int(input())
arr = list(map(int, input().split()))
count = defaultdict(int)
for i in arr:
	count[i]+=1

dp = [0]*(10**5 + 11)
dp[0] = 0
dp[1] = count[1]
for i in range(2,10**5+11):
	dp[i] = max(dp[i-1], dp[i-2] + count[i]*i)
print(dp[n])







