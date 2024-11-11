n,*a=map(int,open(0).read().split())
b=[0]*61
for c in a:
  for i in range(61):b[i]+=2**i&c>0
print(sum(2**i*c*(n-c)for i,c in enumerate(b))%(10**9+7))