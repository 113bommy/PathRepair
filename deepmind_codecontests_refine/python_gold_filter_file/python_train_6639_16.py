M=10**6+1
_,*l=map(int,open(0).read().split())
a=[0]*M
for i in sorted(l):
  a[i]+=1
  if a[i]==1:
    for j in range(2*i,M,i):a[j]+=9
print(a.count(1))