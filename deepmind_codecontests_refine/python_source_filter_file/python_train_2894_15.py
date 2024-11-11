I=lambda:map(int,input().split())
n,q=I()
s=[0]
d=s*n
f=s+[1]*n
e=[[]for _ in d]
while~-n:n-=1;a,b=I();e[a-1]+=b-1,;e[b-1]+=a-1,
while q:q-=1;p,x=I();d[p-1]+=x
while s:
 v=s.pop()
 for w in e[v]:d[w]+=d[v]*f[w];s+=[w]*f[w];f[w]=0
print(*d)