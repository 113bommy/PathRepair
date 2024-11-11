n=int(input())
import math
def prime(n):
	l=[0 for i in range(n+1)]
	for j in range(2,int(math.sqrt(n))+1):
		if l[j]==0:
			k=2*j
			while k<n+1:
				l[k]=1
				k+=j
	return l
def div(n):
	l=[0 for _ in range(n+1)]
	i=2
	while i<n:
		if l[i]==0:
			if n%i==0:
				return i
			j=i
			while j<n+1:
				l=[j]=1
				j+=i
		i+=1
def pebbles(n):
	s=n
	l=prime(n)
	while n>1:
		if l[n]==0:
			return s
		n=int(n/div(n))
		s+=n
		return s+1
print(pebbles(n))
