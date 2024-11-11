n,k=map(int,input().split())
INF=10**18
a=list(map(int,input().split()))
ans=INF
for i in range(2**(n-1)):
  cst=0
  cnt=0
  b=a[0]
  for j in range(n-1):
    if (i>>j) & 1:
      cst+=max(b+1-a[j+1],0)
      b=max(a[j+1],b+1)
      cnt+=1
    elif a[j+1]>b:
      cst+=a[j+1]-b
      b=a[j+1]
  if cnt==k-1:
    ans=min(ans,cst)
print(ans)