import itertools
n,m=map(int,input().split())
a=list(map(int,input().split()))
ans=10**10
if m==0:
  print(0)
  exit()
for i in itertools.combinations(range(1,n),m-1):
  s=list(i)
  mx=a[0]
  cost=0
  for j in range(1,n):
    if j in s:
      if a[j]>mx:
        mx=a[j]
        continue
      else:
        cost+=mx+1-a[j]
        mx+=1
    mx=max(mx,a[j])
  ans=min(cost,ans)
print(ans)