from collections import defaultdict
a,b,m=map(int,input().split())
r=defaultdict(int)
c=defaultdict(int)
d=defaultdict(int)
for i in range(m):
  x,y=map(int,input().split())
  d[(x,y)]=1
  r[x]+=1
  c[y]+=1
z=list()
zz=list()
x=max(r,key=r.get)
y=max(c,key=c.get)
for i in r.keys():
  if r[i]==r[x]:
    z.append(r[i])
for i in c.keys():
  if c[i]==c[y]:
    zz.append(c[i])
flag=False
for i in z:
  for j in zz:
    if d[(i,j)]==0:
      flag=True
      break
if flag==False:
  print(r[x]+c[y]-1)
else:
  print(r[x]+c[y])
  
  
