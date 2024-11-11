'''input
5 10
'''
t = 0
n, m = map(int, input().split())
if n == m:
	print(2 * n // 3)
else:
	for x in range(n+1):
		if m - 2*x >= 0:
			t = max(t, x+min(m - 2*x, (n - x)//2))
	print(t)









