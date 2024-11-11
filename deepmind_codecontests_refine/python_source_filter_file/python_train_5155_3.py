n=int(input())
L=list(map(int,input().split()))
x=min(L)
if(all(e==x for e in L)):
	print(x*n)
else:
	M=[]
	for i in range(0,len(L)):
		if(L[i]==x):
			M.append(i)
	if(len(M)==1):
		print(n*x+(n-1))
	else:
		temp=n+L[-1]-L[0]-1
		for i in range(0,len(M)):
			p=L[i+1]-L[i]-1
			if(p>temp):
				temp=p
			a=(n*x+temp)
		print(a)