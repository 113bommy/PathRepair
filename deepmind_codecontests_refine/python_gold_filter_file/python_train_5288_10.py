*n,t=open(0).read().split()
n,k,r,s,p=map(int,n)
d={'r':p,'s':r,'p':s}
b=['']*n*2
a=0
for i,c in enumerate(t[:n]):
  if c!=b[i-k]:
    b[i]=c
    a+=d[c]
print(a)