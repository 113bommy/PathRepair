n=int(input())
*a,=map(int,input().split())
mod=10**9+7
col=[0]*(n+1)
col[0]=3

ans=1

for i in range(n):
    ans*=col[a[i]]
    col[a[i]]-=1
    col[a[i]+1]+=1
    ans%=mod

print(ans%mod)
