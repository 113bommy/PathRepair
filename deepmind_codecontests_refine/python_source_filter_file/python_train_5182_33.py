f=lambda:[*map(int,input().split())]
n,k=f()
p,c=f(),f()
p=[*map(lambda x:x-1,p)]
a=-1e9
for i in range(n):
  x=i
  l=[]
  s=0
  while 1:
    x=p[x]
    l+=[c[x]]
    s+=c[x]
    if x==i: break
  m=len(l)
  t=0
  for j in range(m):
    if j+1>k: break
    t+=l[j]
    a=max(a,t+(k-j-1)//m*s*(s>0))
print(a)