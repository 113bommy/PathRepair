n,k,*p=map(int,open(0).read().split())
s=m=sum(p[:k])
for i in range(k,n):s+=p[i]-p[i-k];m=max(m,s)  
print((s+k)/2)