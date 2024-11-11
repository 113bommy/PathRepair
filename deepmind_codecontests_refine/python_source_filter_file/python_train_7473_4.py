n=int(input())
mod=10**9+7
c=list(map(int,input().split()))
c.sort()
ans=0
for i in range(n):
    ans+=c[i]*(n-i+2)
    ans%=mod
print(ans*pow(4,n-1,mod)%mod)
