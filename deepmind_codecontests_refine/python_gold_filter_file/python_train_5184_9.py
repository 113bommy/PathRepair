_,a=open(0)
c=1
d=[3]+[0]*10**6
for a in map(int,a.split()):
  c=c*d[a]%(10**9+7)
  d[a]-=1
  d[a+1]+=1
print(c)