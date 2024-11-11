from math import ceil
for _ in  range(int(input())):
  n,x=map(int,input().split())
  m,eff=0,0
  for _ in range(n):
    d,h=map(int,input().split())
    m=max(m,d)
    eff=max(eff,d-h)
  #print(m,x)
  if m>=x:print(1)
  elif eff<=0:print(-1)
  else:x-=m;print(1+ceil((x)/eff))
