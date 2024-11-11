def nfac(n):
	if n==0:
		return 1
	ans=1
	for i in range(1,n+1,1):
		ans*=i
	return ans

def ncr(n,r):
	return nfac(n)/(nfac(n-r)*nfac(r))

n=int(input())

print((ncr(n,n//2)*(nfac(n//2-1)**2))/2)

