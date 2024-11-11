a,b,k=map(int,input().split())
p=[a,b]
i=0
while True:
  for g in range(2):
    t=g^1
    if p[g]%2==1:
      p[g]-=1
    p[t]+=p[g]//2
    p[g]//=2
    i+=1
    if i==k:
      print(*p)
      exit(0)
