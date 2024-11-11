ad=ord('z')-ord('a')+1
def mc(a,b):
	pd=abs(ord(a)-ord(b))
	return min(pd,ad-pd)
	
def fd(v,r):
	for c in r:
		if not v[c]:
			return c
	
def mp(s,n,p):
	cl=n//2
	v=[s[c]==s[-(c+1)] for c in range(cl)]
	rv=range(cl)
	if p>=cl:
		p=n-p-1
	return fd(v,rv),fd(v,rv[::-1]),p
	
def d(s,n,p):
	l,r,p=mp(s,n,p)
	if l==None:
		return 0
	t=0
	for c in range(l,r+1):
		t+=mc(s[c],s[-(c+1)])
	lp,rp=abs(p-l),abs(r-p)
	if l<p<r:
		if lp>rp:
			lp,rp=rp,lp
		t+=2*lp+rp
	else:
		t+=r-l+min(lp,rp)
	return t

n,p=[int(c) for c in input().split()]
s=input()
print(d(s,n,p-1))