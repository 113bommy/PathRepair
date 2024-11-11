n,x=map(int,input().split())
a=list(map(int,input().split()))
b=[[None for _ in [0]*n] for _ in [0]*n]

for i in range(n):
	m=a[i]
	for j in range(n):
		k=i-j
		if k<0:
			k+=n
		m=min(m,a[k])
		b[j][i]=m

m=10**15
for i,j in enumerate(b):
	m=min(m,sum(j)+x*i)
print(m)