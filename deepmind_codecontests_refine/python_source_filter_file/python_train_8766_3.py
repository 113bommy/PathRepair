T = 1
for test_no in range(T):
	x0, y0, ax, ay, bx, by = map(int, input().split())
	xs, ys, t = map(int, input().split())
 
	LIMIT = 2 ** 62 - 1
	x, y = [x0], [y0]
	while ax * x[-1] + bx<=10**16 and ay * y[-1] + by<=10**16:
	    a=ax * x[-1] + bx
	    b=ay * y[-1] + by
	    x.append(a)
	    y.append(b)
	
	n = len(x)
	ans = 0
	for i in range(n):
		for j in range(i, n):
			length = x[j] - x[i] + y[j] - y[i]
			dist2Left = abs(xs - x[i]) + abs(ys - y[i])
			dist2Right = abs(xs - x[j]) + abs(ys - y[j])
			if (length <= t - dist2Left or length <= t - dist2Right): 
			    ans = max(ans, j-i+1)
	
	print(ans)