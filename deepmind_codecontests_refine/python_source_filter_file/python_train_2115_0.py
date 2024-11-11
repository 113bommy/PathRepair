from collections import Counter
import heapq
import sys
input = sys.stdin.readline

for nt in range(int(input())):
	n = int(input())
	a = list(map(int,input().split()))
	c = Counter(a)
	maxx = []
	for i in c:
		maxx.append(c[i])
	m = max(maxx)
	ans = 0
	if n%2 and maxx.count(m)==1:
		m -= 1
		ans = 1
	print (ans + max(0, 2*m-n+ans))