
from sys import stdin,stdout
input=stdin.readline 
import math,bisect
#from itertools import permutations
#from collections import Counter

prime=[1]*102001
prime[1]=0
prime[0]=0
for i in range(2,102001):
	j=i
	if prime[i]==1:
		while(j+i<100):
			j+=i
			prime[j]=0
#print(prime)
l=[]
n,m=map(int,input().split())
for i in range(n):
	t=list(map(int,input().split()))
	l.append(t)

ans=5000000000
for i in range(n):
	tot=0
	for j in range(m):
		ele=l[i][j]
		for k in range(ele,102001):
			if prime[k]==1:
				tot+=k-ele
				break
	ans=min(ans,tot)

for j in range(m):
	tot=0
	for i in range(n):
		ele=l[i][j]
		for k in range(ele,102001):
			if prime[k]==1:
				tot+=k-ele
				break
	ans=min(ans,tot)


print(ans)