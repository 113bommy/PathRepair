from collections import defaultdict
n=int(input())
d=defaultdict(int)

while n%2==0:
  n//=2
  d[2]+=1
f=3

while f*f<n:
  if n%f==0:
    n//=f
    d[f]+=1
  else:
    f+=2
if n!=1:
  d[n]+=1
c=0
for k,v in d.items():
  i=1
  while v>=i:
    v-=i
    c+=1
    i+=1
print(c)
    