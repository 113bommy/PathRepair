k,n,*a=map(int,open(0).read().split())
a+=[k+a[0]]
print(min(y-x for x,y in zip(a,a[1:])))