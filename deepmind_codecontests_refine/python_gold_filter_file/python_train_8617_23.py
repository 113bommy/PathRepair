f=input; n=int(f()); s=list(f())
d={chr(97+i):[0]*(n+1) for i in range(26)}
def bsum(k,i):
  s=0
  while i: s+=d[k][i]; i-=i&-i
  return s
def badd(k,i,x):
  while i<=n: d[k][i]+=x; i+=i&-i
for i in range(n): badd(s[i],i+1,1)
for i in range(int(f())):
  a,b,c=f().split(); b=int(b)-1
  if a>'1': print(sum(1 for k in d.keys() if bsum(k,int(c))-bsum(k,b)))
  else: badd(s[b],b+1,-1); s[b]=c; badd(c,b+1,1)