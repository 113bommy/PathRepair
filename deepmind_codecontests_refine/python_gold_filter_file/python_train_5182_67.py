N,K=map(int,input().split())
P=list(map(int,input().split()))
C=list(map(int,input().split()))

dummy=set()
loop=[]
X=set(range(N))
while len(dummy)!=N:
  a=[]
  k=min(X-dummy)
  a.append(k)
  dummy.add(k)
  l=P[k]-1
  while l!=k:
    a.append(l)
    dummy.add(l)
    l=P[l]-1
  loop.append(a)

ans=-(10**300)
for l in loop:
  temp=0
  s=len(l)
  ssum=0
  k=0
  for i in range(s):
    ssum+=C[l[i]]
  if ssum>0:
    temp+=((K-1)//s)*ssum
    k=K-((K-1)//s)*s
  else:
    k=min(K,s)
  kmax=-(10**300)
  for ii in range(s):
    tempscore=temp
    for jj in range(1,k+1):
      tempscore+=C[l[(ii+jj)%s]]
      if tempscore>kmax:
        kmax=tempscore
  if kmax>ans:
    ans=kmax
print(ans)
