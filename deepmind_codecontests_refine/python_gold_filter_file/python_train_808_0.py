n,*a=map(int,open(0).read().split())
c=0
for i in range(61):t=sum(2**i&b>0for b in a);c+=t*(n-t)*2**i
print(c%(10**9+7))