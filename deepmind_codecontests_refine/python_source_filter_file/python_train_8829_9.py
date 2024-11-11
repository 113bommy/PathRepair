n,*l=map(int,open(0).read().split())
a=sorted([l[i]-i-1for i in range(n)])
f=lambda x:sum(abs(l[i]-i-1-x)for i in range(n))
print(min(f(a[n//2]),f(a[n//2+1])))