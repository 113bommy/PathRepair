n,k,*a=map(int,open(0).read().split())
d={}
s=1
while k:k-=1;s=a[s-1];k%=d.get(s,2**61)-k;d[s]=k
print(s)