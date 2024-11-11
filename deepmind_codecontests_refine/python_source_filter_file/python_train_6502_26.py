def ncr(n):
	prod=n*(n-1)
	return (prod/2)

n,m=[int(x) for x in input().split()]
mini=ncr(n-m+1)
maxi=(n%m)*ncr(n//m+1)+(m-(n%m))*ncr(n//m)
import math
print(math.ceil(maxi),math.ceil(mini))