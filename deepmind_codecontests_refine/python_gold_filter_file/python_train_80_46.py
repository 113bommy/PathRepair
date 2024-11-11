n,_,*a=map(int,open(0).read().split())
a=set(a)
c,d=1,0
for i in range(n):n=(c+d)%(10**9+7)*(not-~i in a);c,d=n,c
print(n)