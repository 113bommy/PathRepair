from heapq import*
def f():global d,r;e=min(a[t],d);a[t]-=e;d-=e;r+=x*e
R=lambda:[*map(int,input().split())]
n,m=R()
a,c=R(),R()
b=[*zip(c,range(n))]
heapify(b)
s=''
for _ in[0]*m:
 t,d=R();t-=1;r=0;x=c[t];f()
 while d and b:
  x,t=b[0];f()
  if a[t]==0:heappop(b)
 if d:r==0
 s+=f'{r} '
print(s)