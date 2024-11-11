n=int(input())
c=list(map(int,input().split()))
c.sort(reverse=True)
res=0
ans=0
mod=10**9+7
p=pow(2,n*2-2,mod)
for i in range(n):
   ans+=(c[i]*(i+2)%mod)*p
print(ans%mod)
