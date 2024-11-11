k,n,*a=map(int,open(0).read().split())
l=k-a[n-1]+a[0]
for i in range(n-1):
  l=max(l,a[i+1]-a[i])
print(k-l)