# import sys
# sys.stdin = open('cf591d.in')

x1, y1, x2, y2 = map(int, input().split())
vmax, t = map(int, input().split())
vx, vy = map(int, input().split())
wx, wy = map(int, input().split())

c1x = x1 + vx * t
c1y = y1 + vy * t
r1 = t * vmax

if (c1x - x2)**2 + (c1y - y2)**2 <= r1**2:
	# can get before wind changes
	t1l, t1r = 0, t
	itr = 0
	while t1r - t1l > 1e-10 and itr < 200:
		itr += 1
		# build first circle
		t1 = (t1l + t1r) / 2
		cc1x = x1 + vx * t1
		cc1y = y1 + vy * t1
		rr1 = t1 * vmax
		if ((cc1x - x2)**2 + (cc1y - y2)**2) <= rr1**2:
			t1r = t1
		else:
			t1l = t1
	print(t1)
else:
	t2l, t2r = 0, 200000000
	itr = 0
	while t2r - t2l > 1e-10 and itr < 200:
		itr += 1
		# build second circle
		t2 = (t2l + t2r) / 2
		c2x = x2 - wx * t2
		c2y = y2 - wy * t2
		r2 = t2 * vmax
		# check for intersection
		if ((c1x - c2x)**2 + (c1y - c2y)**2) <= (r1 + r2)**2:
			t2r = t2
		else:
			t2l = t2
	print(t + t2)