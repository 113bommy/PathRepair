from math import gcd
n=int(input())
a=list(map(int,input().split()))
cnt=0
for i in range(n):
  if a[i]==1:
    cnt+=1
if cnt>0:
  print(n-1-cnt)
  exit()
ans=10**18
for l in range(n):
  g=a[l]
  r=l+1
  while r<n:
    g=gcd(g,a[r])
    if g==1:
      break
    r+=1
  if g==1:
    ans=min(ans,r-l+n-1)
if ans==10**18:
  print(-1)
else:
  print(ans)