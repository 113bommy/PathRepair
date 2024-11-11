import sys
import math as mas

def sieve(n):
	p=[True for i in range(n+1)]
	p[0]=p[1]=False
	end=int(n**0.5)
	for i in range(2,end+1):
		if p[i]:
			for j in range(i*i,n+1,i):
				p[j]=False
	return p
	
sosu=sieve(1000010)
for i in sys.stdin:
	print(sum(sosu[t] for t in range(int(i))))

#	a,b=map(int,i.split())
#	print(gcd(a,b),lcm(a,b))