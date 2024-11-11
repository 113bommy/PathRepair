n=int(input())
a=list(map(int,input().split()))
ans=0
tmp=0
for i in range(N):
  tmp+=a[i]
  if i%2==0:
    if tmp<=0:
      ans+=abs(tmp)+1
      tmp=1
  else:
    if tmp>=0:
      ans+=abs(tmp)+1
      tmp=-1

tmp=0
tmp2=0
for i in range(N):
  tmp+=a[i]
  if i %2==0:
    if tmp>=0:
      tmp2+=abs(tmp)+1
      tmp=-1
  else:
    if tmp<=0:
      tmp2+=abs(tmp)+1
      tmp=1
print(min(ans,tmp))
    