def mc(v,d,n):
	"""get move count"""
	r=0
	for c in range(n-1):
		vd=v[c]-v[c+1]
		cr=(vd//d+1) if vd>=0 else 0
		v[c+1]+=cr
		r+=cr
	return r

n,d=[int(c) for c in input().split()]
v=[int(c) for c in input().split()]
print(mc(v,d,n))