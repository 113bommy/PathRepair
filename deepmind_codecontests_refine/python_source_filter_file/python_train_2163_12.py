n=int(input())
a=list(map(int,input().split()))
ans=sum(a)*sum(a)
for i in range(n):
  ans-=a[i]*a[i]
ans/=2
mod=10**9+7
ans%=mod
print(ans)