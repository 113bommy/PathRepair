n=int(input())
l=[int(c) for c in input().spilt()]
ans=0
mod=10**9+7
for i in range(60):
  s=sum(a>>i&1 for a in l)
  ans+=s*(n-s)<<i%mod
  ans%=mod
print(ans)
