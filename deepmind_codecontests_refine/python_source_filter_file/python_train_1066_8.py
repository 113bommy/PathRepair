t = int(input())


for i in range(t):
	mn = 1e10
	mx = 0
	n, x, m = map(int, input().split())
	for _ in range(m):
		l, r = map(int, input().split())
		if(not mx and l <= x <= r):
			#print(mx)
			mn = min(mn, l)
			mx = max(mx, r)
			#print(mx, mn)
		else:
			if(l <= mn <= r or l <= mx <= r):
				mn = min(mn, l)
				mx = max(mx, r)
				# print(mn, mx)
				# print(l, r)
			elif(mn <= l <= mx or mn <= r <= mx):
				mn = min(mn, l)
				mx = max(mx, r)
				# print(mn, mx)
				# print(l, r)
	if(mx):
		print(mx - mn + 1)
	else:
		print(0)