for i in range(int(input())):
	a , b , c = map(int,input().split())
	s = abs(a - b)
	get = 2 *(s + 1)
	mid = get // 2
	if a == mid and b != 2 * mid or b == mid and a != 2 *mid:
		print(-1)
	elif min(a , b) + mid != max(b,a) or c > get or a > get or b > get:
		print(-1)
	else:
		print(c + mid if c <= mid else max(c - mid , 1))
		# 	print(c + mid)
		# else:
		# 	print(max(c - mid , 1))