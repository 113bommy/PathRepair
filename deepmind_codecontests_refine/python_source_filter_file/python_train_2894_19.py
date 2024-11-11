(n,q),*t=[map(int,t.split())for t in open(0)]
s=[0]
d=s*n
f=s+[1]*n
e=[[]for _ in d]
for a,b in t:
 if~-n:n-=1;e[a-1]+=b-1,;e[b-1]+=a-1,
 else:d[a-1]+=b
while s:
 v=s.pop()
 for w in e[v]:d[w]+=d[v]*f[w];s+=[w]*f[w];f[w]=0
print(*d)