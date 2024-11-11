r=lambda x:p[x]>=0and r(p[x])or x
(n,m,k),*t=[map(int,t.split())for t in open(0)]
p,f=[-1]*-~n,[-1]*-~n
for a,b in t[:m]:
  x,y=r(a),r(b)
  if x!=y:
    if x>y:x,y=y,x
    p[x]+=p[y]
    p[y]=x
  f[a]-=1,
  f[b]-=1,
a=[f[i]-p[r(i)]for i in range(n+1)]
for c,d in t[m:]:
  if r(c)==r(d):
    a[c]-=1
    a[d]-=1
print(*a[1:])