M,z,s=998244353,1,0
N,*A=map(int,open(0))
d=[1]+[0]*7**6
e=[1]+[0]*7**6
for a in A:
 i=s;s+=a;z*=3
 while~i:d[i+a]+=d[i]%M;d[i]*=2;e[i+a]+=e[i]%M;i-=1
i=s
while i*2>=s:z=(z-d[i]*3)%M;i-=1
print(z+~s%2*e[s//2]*3%M)