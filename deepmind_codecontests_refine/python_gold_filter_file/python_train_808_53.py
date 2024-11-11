n=int(input())
A=list(map(int,input().split()))
mod=10**9+7
ans=0
for i in range(62):
    cnt=0
    for j in range(n):
        cnt+=(A[j]>>i)&1
    ans+=cnt * (n-cnt) *(2**i)%mod
print(ans%mod)