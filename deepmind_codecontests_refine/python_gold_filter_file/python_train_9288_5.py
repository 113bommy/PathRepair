# x + ceil(d/(x+1)) <= n
from math import ceil, sqrt
K = 10000
 
for case in range(int(input())):
	n, d = map(int, input().split())
	D = (n - 1) ** 2 - 4 * (d - n)
	if D < 0:
		D = 0
	x = int((n - 1 + sqrt(D)) / 2)
	start = 0 if x < K else x - K
	end = x + K
	ans = "NO"
	for i in range(start, end):
		if i + ceil(d / (i+1)) <= n:
			ans = "YES"
			break
	print(ans)