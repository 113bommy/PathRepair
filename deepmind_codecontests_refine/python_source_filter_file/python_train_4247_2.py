n,*s=map(int,open(0).read().split());s,t,f,g=[s[i*n:i*n+n]for i in range(4)];r=range(n);a=[n*[0]for _ in r]
e=enumerate
for b in range(64):
 y=1<<b;u=[k&y for k in f];v=[k&y for k in g];l=[0]*n;m=l[:]
 for i,k in e(u):
  for j,l in e(v):
   if(k&l)|((s[i]^1)*k)|((t[j]^1)*l):a[i][j]|=y;l[i]+=1;m[j]+=1
 for i in r:
  if(l[i]==0)*s[i]*u[i]:
   for j in r:
    if(t[j]^1)*(n-m[j]>1):a[i][j]|=y;m[j]+=1;break
  if(m[i]==0)*t[i]*v[i]:
   for j in r:
    if(s[j]^1)*(n-l[j]>1):a[j][i]|=y;l[j]+=1;break
h=a[0][:];w=[i[0]for i in a]
for i,k in e(a):
 for j,l in e(k):w[i]=(l|w[i]if s[i]else w[i]&l);h[j]=(l|h[j]if t[j]else h[j]&l)
if(g!=h)|(f!=w):print(-1);exit() 
for i in a:print(*i)