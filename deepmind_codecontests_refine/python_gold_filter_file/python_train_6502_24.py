n, m = map(int, input().split())


if m == 1:
	ans = (n*(n-1))//2
	print(ans, ans)


elif n == m:
	print(0, 0)

else:

	s = n-m

	kmax = ((s+1)*(s))//2

	f = n//m
	r = n%m

	total = 0

	total+= ((f)*(f-1))//2

	total*=(m-r)

	t2=((f+1)*(f))//2
	t2*=r

	total+=t2

	print(total, kmax)