n,k=map(int,input().split())
a=list(map(int,input().split()))
sum_a=[0]*(n+1)
b=[max(0,a[i]) for i in range(n)]
sum_b=[0]*(n+1)
sum_a[1]=a[0]
sum_b[1]=a[0]
for i in range(1,n):
  sum_a[i+1]=sum_a[i]+a[i]
  sum_b[i+1]=sum_b[i]+b[i]
ans=-10**18
for i in range(n-k+1):
  l,r=i,i+k
  cnt=sum_b[l]-sum_b[0]
  cnt+=max(0,sum_a[r]-sum_a[l])
  cnt+=sum_b[n]-sum_b[r]
  ans=max(ans,cnt,)
print(ans)