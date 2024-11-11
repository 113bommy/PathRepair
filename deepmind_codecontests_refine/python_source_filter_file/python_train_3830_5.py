f=lambda:map(int,input().split())
n,k=f()
lm,lp=[],[]
for i in f():
  if i<0: lm.append(-i)
  else: lp.append(i)
lm.sort()
lp.sort()
cm=len(lm)
cp=len(lp)
def cnt(x):
  c=0
  if x<0:
    r=cp
    for i in lm:
      while r and i*lp[r-1]>-x: r-=1
      c+=cp-r
    return c
  r=cm
  for i in lm:
    while r and i*lm[r-1]>=x: r-=1
    c+=r
    if i*i<x: c-=1
  r=cp
  for i in lp:
    while r and i*lp[r-1]>=x: r-=1
    c+=r
    if i*i<x: c-=1
  return cm*cp+c//2
INF=10**18+1
l,r=-INF,INF
while r-l>1:
  m=l+r>>1
  if cnt(m)<k: l=m
  else: r=m
print(l)