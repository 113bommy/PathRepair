def factory(a,m):
	s = set()
	while a%m != 0:
		r = a%m
		if r in s:
			return False
		else:
			a += r
			s.add(r)
	return True

a,m = map(int, input().split())
if factory(a,m):
	print("YES")
else:
	print("NO")