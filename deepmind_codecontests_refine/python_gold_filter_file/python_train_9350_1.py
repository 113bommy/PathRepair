n,k=map(int,input().split())
x=list(map(int,input().split()))
c=10**9
for i in range(n-k+1):
	h=x[i]
	m=x[i+k-1]
	H=abs(h)
	M=abs(m)
	if h*m<0:
		c=min(c,2*H+M,2*M+H)
	else:
		c=min(c,max(M,H))
print(c)