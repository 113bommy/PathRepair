from math import gcd, ceil 
from collections import defaultdict, deque
from sys import stdin,stdout
from bisect import bisect_left, bisect_right
from copy import deepcopy
 
inp=lambda : int(stdin.readline())
sip=lambda : stdin.readline()
mulip =lambda : map(str, stdin.readline().split())
lst=lambda : list(map(int,stdin.readline().split()))
slst=lambda: list(sip())
M = pow(10,9)+7
#-----------------------------------------------------
for _ in range(inp()):
	n = inp()
	s = list(input())
	if(s[0]=='1' or s[n-1]=='1'):
		print(2*n)
	else:
		maxx,tmp = 0, 0
		for i in range(n):
			if(s[i]=='1'):
				maxx = max(maxx,2*(i+1))
				maxx = max(maxx,2*(n-i-1))
				tmp += 1
		maxx = max(maxx,tmp+n)
		print(maxx)



