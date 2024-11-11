def fac(x):
	if x==1:
		return 1
	return x*fac(x-1)

def C(n,m):
	return fac(n)/(fac(m)*fac(n-m))

n=int(input())
ans = C(n,n/2)/2
ans = ans*(fac(n/2)/(n/2))
ans = ans*(fac(n/2)/(n/2))
print(ans)