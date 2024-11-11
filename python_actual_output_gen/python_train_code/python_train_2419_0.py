n = int(input())
a = list(map(int, input().split()))
x = int(input())
if x >= 0:
	if sum(a) + x * (n >> 1) > 0:
		print(n)
	else:
		print(-1)
else:
	m = float('inf')
	t = len(a)
	s = sum(a)
	for i in range(t):
		m = min(m, t - i + (s - 1 // -x)) 
		if m < t: break
		if m >= n - i:
			print(n - i)
			exit()
		s -= a[i]
	print(-1)