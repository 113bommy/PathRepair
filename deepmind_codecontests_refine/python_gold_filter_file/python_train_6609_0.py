import sys
input=lambda:sys.stdin.readline().strip()
print=lambda s:sys.stdout.write(str(s)+"\n")
nn=int(input())
dp=[1] + [0]*(nn+1)
for _ in range(nn):
	l, r = map(int, input().split())
	c = 1
	n = 0
	for _ in range(19):
		n += max(0, min(r, 2 * c - 1) - max(l, c) + 1)
		c *= 10
	p=n/(r-l+1)
	dp=[dp[0]*(1-p)]+[dp[j]*(1-p)+dp[j-1]*p for j in range(1,nn+1)]
from math import *
print (sum(dp[int(ceil(nn*int(input())/100)):]))
