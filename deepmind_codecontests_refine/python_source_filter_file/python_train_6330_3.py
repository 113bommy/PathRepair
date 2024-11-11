M=998244353
N,*A=open(0)
d=[1]+[0]*7**6
e=[1]+[0]*7**6
z=1
s=0
for a in A:
	a=int(a);s+=a;i=s;z*=3
	while~i:d[i]+=d[i]+d[i-a]%M;e[i]+=e[i-a];i-=1
i=s
while i*2>=s:z-=d[i]*3;i-=1
print((z+~s%2*e[s//2]*3)%M)