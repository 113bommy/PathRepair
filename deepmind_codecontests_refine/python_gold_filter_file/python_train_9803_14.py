def primes(n): 
	allp=[]
	prime = [True for i in range(n+1)] 
	p = 2
	while (p * p <= n): 
		if (prime[p] == True): 
			for i in range(p * p, n+1, p): 
				prime[i] = False
		p += 1
	for p in range(2, n): 
		if prime[p]: 
			allp.append(p)
	return allp
n=int(input())
l=[0]*(n-1)
k=1
allp=primes(n+1)
for i in allp:
	for j in range(i,n+1,i):
		if l[j-2]==0:
			l[j-2]=k
	k+=1
for i in l:
	print (i,end=" ")