a1, b1, c1 = map(int, input().split())
a2, b2, c2 = map(int, input().split())

if a1 == b1 == a2 == b2 == 0 and c1 !=0 and c2 != 0:
	print("0")

else:
	x = a1 * b2
	y = a2 * b1
	p = b1 * c2
	q = b2 * c1
	r = a1 * c2
	s = a2 * c1

	if x != y:
		print("1")
	elif x == y and p == q and r == s:
		print("-1")
	else:
		print("0")