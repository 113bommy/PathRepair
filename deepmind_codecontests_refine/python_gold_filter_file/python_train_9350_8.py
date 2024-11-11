N,K=map(int,input().split())
a=list(map(int,input().split()))

ans=10**11

for i in range(N-K+1):
    ans=min(ans, abs(a[i])+a[i+K-1]-a[i], abs(a[i+K-1])+a[i+K-1]-a[i] )

print(ans)