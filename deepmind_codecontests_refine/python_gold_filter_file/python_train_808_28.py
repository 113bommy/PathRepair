n=int(input())
a=list(map(int,input().split()))
mod=10**9+7
cnt=[0]*60
for elem in a:
    for i in range(60):
        cnt[i]+=(elem>>i)%2
ans=0
for i in range(60):
    ans+=((cnt[i]*(n-cnt[i]))<<i)%mod
print(ans%mod)