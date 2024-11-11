n,k,*a=map(int,open(0).read().split())
l,r,*b=[[]for _ in range(10**6)]
for i,v in enumerate(a):
  b[v]+=i,
  l+=len(b[v]),
s=a[0]
i=c=0
while 1:
  j=l[i]%len(b[s])
  if(c>k-2)>j:
    r+=s,
    i+=1
  else:i=-~b[s][j]%n
  c+=j<1
  if i<1:
    if c>k-2:break
    k%=c+1
    c=0
  s=a[i]
print(*r)