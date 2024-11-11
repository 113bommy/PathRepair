from bisect import*
R=lambda:[*map(int,input().split())]
n,m=R()
a,c=R(),R()
b=sorted(zip(c,range(n)))
for _ in[0]*m:
 t,d=R();t-=1;r=0
 if a[t]:e=min(a[t],d);a[t]-=e;d-=e;r+=c[t]*e;i=0
 for x,j in b:
  e=min(a[j],d);a[j]-=e;d-=e;r+=x*e
  if d==0:break
  i+=1
 b[:i]=[]
 print((0,r)[d==0])