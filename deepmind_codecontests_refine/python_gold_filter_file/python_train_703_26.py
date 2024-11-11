def resolve():
	n,m = map(int,input().split())
	sc = [tuple(map(int,input().split())) for _ in range(m)]
	for i in range((10**(n-1) if n!=1 else 0),10**n):
		c = 1
		for j in sc:
			if str(i)[j[0]-1] != str(j[1]):
				c = 0
				break
		if c: break
	print(i if c else -1)
    
resolve()