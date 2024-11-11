M=998244353
N=int(input())
d=[0]*90001
d[0]=1
e=[0]*90001
e[0]=1
z=1
s=0
for _ in range(N):
	a=int(input())
	i=s
	while i>=0:
		d[i+a]+=d[i]%M
		d[i]*=2
		e[i+a]+=e[i]%M
		i-=1
	s+=a
	z=z*3%M
for i in range(s+1>>1,s+1):
	z-=d[i]*3
	z%=M
print([(z+e[s//2]*3)%M,z][s%2])
