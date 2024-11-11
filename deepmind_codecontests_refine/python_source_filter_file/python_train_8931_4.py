n,k=map(int,input().split())
sump=0
for i in range(1,n+1):
  cnt=i
  p=1/i
  while cnt<k:
    p*=1/2
    cnt*=2
  sump+=p
print(sump)