*t,s=open(0).read().split()
n,k,r,s,p=map(int,t)
d={'r':p,'s':r,'p':s}
b=['']*n*2
a=0
for i,c in enumerate(s[:n]):
  if c!=b[i-k]:
    b[i]=c
    a+=d[c]
print(a)