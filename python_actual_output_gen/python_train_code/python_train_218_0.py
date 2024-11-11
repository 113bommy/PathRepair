n,m,*t,d=map(int,open(0).read().split())
d=[0]*2+[1e18]*n
for l,r,c in sorted(zip(*[iter(t)]*3)):
 for i in range(r,l,-1):
  if d[l]+c<d[i]:d[i]=d[l]+c
  else:break
print(d[-2]%10**18or-1)
