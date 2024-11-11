n,k,m,t=map(int,input().split())
for i in range(t):
	bj,p=map(int,input().split())
	if bj==0:
		n1=p
		n2=n-p
		if k>p:
			n=n2
			k=k-p
		elif k<=p:
			n=n1
	elif bj==1:
		if k>=p:
			k=k+1
			n=n+1
		elif k<p:
			n=n+1
	print(n,k,sep=' ')
			
		