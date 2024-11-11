from sys import stdin
input=lambda : stdin.readline()
from math import ceil,sqrt,gcd
n,k=map(int,input().split())
z=[k+1+i for i in range(k+1)]
if 2*k+1>=n:
	print(1)
	print(ceil(n/2))
else:
	a=n//(2*k+1)
	r=n%(2*k+1)
	if r==0:
		print(a)
		i=k+1
		while i<=n:
			print(i,end=' ')
			i+=2*k+1
	else:
		if r in z:
			print(a+1)
			i=z.index(r)+1 
			while i<=n:
				print(i,end=' ')
				i+=2*k+1
		else:
			# l=[]
			r+=2*k+1
			for i in range(len(z)):
				for j in range(len(z)):
					if z[i]+z[j]==r:
						x=i
						b=j
						break
			print(a+1)
			l=[n-b]
			i=x+1
			# print(x,b)
			while i<n-b:
				l.append(i)
				i+=2*k+1
			print(*sorted(l))

