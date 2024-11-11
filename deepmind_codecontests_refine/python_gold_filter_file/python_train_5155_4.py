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
		temp=n-M[-1]+M[0]-1
		for i in range(0,len(M)-1):
			p=M[i+1]-M[i]-1
			if(p>temp):
				temp=p
			a=(n*x+temp)
		print(a)