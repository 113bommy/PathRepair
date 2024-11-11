q = int(input())
for i in range(q):
	k, n, a, b = map(int, input().split())
	l = 0
	r = min(k//a, n+1)
	while r-l > 1:
		mid = (r+l)//2
		if mid*a + (n-mid)*b <= k:
			l = mid
		else:
			r = mid
	if k <= b*n:
		print(-1)
	else:
		print(l)