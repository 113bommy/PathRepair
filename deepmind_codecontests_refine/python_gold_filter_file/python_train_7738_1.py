def pn(n):
	"""get prime numbers less or equal n"""
	n+=1
	v=n*[1]
	for d in range(2,n):
		if not v[d]:
			continue
		for c in range(2*d,n,d):
			v[c]=0
	rv=[c for c in range(2,n) if v[c]]
	return rv
	
def ff(v,t):
	"""find first equal or grande than t"""
	for c in range(len(v)):
		if v[c]>=t:
			return c
	
def ip(v,p):
	"""is possible p=any prim+next prim+1"""
	t=(p-1)//2
	r=ff(v,t)
	if r==None:
		return 0
	tv=v[:r+1]
	for c in range(len(tv)-1):
		if v[c]+v[c+1]==p-1:
			return 1
	return 0

def ipp(v,k):
	"""is possible get k primes by Noldbah"""
	r=0
	for c in v:
		if ip(v,c):
			r+=1
		if r==k:
			return 1
	return 0

n,k=[int(c) for c in input().split()]
pv=pn(n)
s='YES' if ipp(pv,k) else 'NO'
print(s)

