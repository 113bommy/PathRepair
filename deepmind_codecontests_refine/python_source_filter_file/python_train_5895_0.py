import sys
import math
from collections import defaultdict,deque
def get(ind ,arr):
	n = len(arr)
	for i in range(n):
		t,l,r = arr[i]
		if t == 1:
			if l <= ind <= r:
				if ind == l:
					ind = r
				else:
					ind -= 1
			continue
		if t == 2:
			if l <=ind <= r:
				ind = (r - ind + l)
			continue
	return ind
n,q,m = map(int,sys.stdin.readline().split())
arr = list(map(int,sys.stdin.readline().split()))
l = []
for i in range(q):
	a,b,c = map(int,sys.stdin.readline().split())
	l.append([a,b,c])
l.reverse()
b = list(map(int,sys.stdin.readline().split()))
ans = []
for i in range(m):
	x = get(b[i],l)
	ans.append(x)
print(*ans)