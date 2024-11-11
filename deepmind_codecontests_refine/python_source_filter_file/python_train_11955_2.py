(n,m),a,*q=[map(int,t.split())for t in open(0)]
t=[-1]*n
def r(x):
 while-1<t[x]:x=t[x]
 return x
def u(x):
 x,y=map(r,x)
 if x!=y:
  if t[x]>t[y]:x,y=y,x
  t[x]+=t[y];t[y]=x
map(u,q)
i=c=0
k,*b=n+~m<<1,
*d,=eval('[],'*n)
for v in a:d[r(i)]+=v,;i+=1
print(k<1and'0'or(k>n)*'Impossible'or exec('for p in d:x,*y=sorted(p)+[0];c+=x;b+=y[:-1];k-=p>[]')or c+sum(sorted(b)[:k]))