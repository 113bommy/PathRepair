n,k,*v=map(int,open(0).read().split())
m=0
r=range
for i in r(n+1):
 for j in r(min(k,n)-i+1):
  t=sorted(v[:i]+v[:-j:-1])
  while t and(k-i-j)*t[0]<0:t.pop(0);j+=1
  m=max(m,sum(t))
print(m)