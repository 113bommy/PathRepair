
# Problem: C. Perfect Team
# Contest: Codeforces - Educational Codeforces Round 73 (Rated for Div. 2)
# URL: https://codeforces.com/contest/1221/problem/C
# Memory Limit: 256 MB
# Time Limit: 2000 ms
# Powered by CP Editor (https://github.com/cpeditor/cpeditor)

from sys import stdin
from math import floor
def get_ints(): return list(map(int, stdin.readline().strip().split()))

for _ in range(int(input())):
	c,m,x = get_ints()
	total = c+m+x
	if min(c,m)==0 or total < 3:
		print(0)
		continue

	k = min(c,m)
	if k <= x:
		print(k)
		continue
	else:
		print(min(total//3,k))
		continue
