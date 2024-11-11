i=lambda:[*map(int,input().split())]
n,m=i()
r=range
u=lambda:sum((i()for _ in r(n)),[])
a=u()
b=u()
for _ in r(n*m):
 if a[_]>b[_]:a[_],b[_]=b[_],a[_]
f=lambda x:any((_%m)*(x[_-1]>=x[_])|(_>=m)&(x[_-m]>=x[_])for _ in r(n*m))
print(["P","Imp"][f(a)|f(b)]+"ossible")