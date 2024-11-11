n,x,*a=map(int,open(0).read().split());r=0
for i in range(1,N):e=max(a[i]+a[i-1]-x,0);a[i]-=min(e,a[i]);r+=e
print(r)