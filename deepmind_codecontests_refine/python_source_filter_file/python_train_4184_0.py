a=[]
for i in range(100):
 b=[0]+[-1]*9;l=[0];k=0
 while l:
  m=[];k+=1
  for x in l:
   for j in(i//10,i%10):
    y=(x+j)%10
    if b[y]<0:b[y]=k;m+=y,
  l=m
 a+=b,
r=[0]*100
s=*map(int,input()),
for x,y in zip(s,s[1:]):
 for i in range(100):
  if r[i]>=0:
   d=a[i][(y-x)%10]
   if d<0:r[i]=-1
   else:r[i]+=d-1
print(*r)