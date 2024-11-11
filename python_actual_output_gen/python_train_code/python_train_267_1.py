n,k,m,t = map(int,input().split())
usize = n
for i in range(t):
	a,b = map(int,input().split())
	if (a == 0):
		if (k <= b):
			usize = b
		else:
			usize = usize - b
			k = k - b
	else:
		if (k >= b - 1):
			k = k + 1
		usize = usize + 1
	print (usize,k)
