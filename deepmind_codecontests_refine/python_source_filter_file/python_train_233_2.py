import math
from sys import stdin
def put():  return  map(int, stdin.readline().split())
def ncr(n, r, p): 
    # initialize numerator 
    # and denominator 
    num = den = 1 
    for i in range(r): 
        num = (num * (n - i)) % p 
        den = (den * (i + 1)) % p 
    return (num * pow(den,  
            p - 2, p)) % p 
def inv(a,b):
    g = math.gcd(b,m)
    return (pow(b, m-2, m)*(a%m))%m
import math
for _ in range(1):
	# n=int(input())
	n,k=put()
	l=[]
	r=[]
	for i in range(n):
		a,b=put()
		l.append(a)
		r.append(b)
	s=0
	ans=0
	l.sort()
	r.sort()
	indl=0
	indr=0
	m = 998244353
	C = [0]*(n+1)
	C[k-1] = 1
	for i in range(k, n+1):
	    C[i] = inv(C[i-1]*(i%m),(i-k+1)%m)
	    C[i]%= m
	while(indl<n and indr<n):
		# print(indl,ans)
		if(l[indl]<r[indr]):
			indl+=1
			if((s)>=(k-1)):
				ans+=C[s]
			s+=1
		elif(l[indl]>r[indr]):
			indr+=1
			s-=1
		else:
			indl+=1
			indr+=1
			if((s)>=(k-1)):
				ans+=C[s]
		
	print(int(ans)%998244353)
	