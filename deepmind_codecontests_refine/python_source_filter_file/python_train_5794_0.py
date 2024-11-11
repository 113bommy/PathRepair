n,k=list(map(int,input().split()))
a=list(map(int,input().split()))
dp=[0 for _ in range(n)]

for i in range(0,n):
    if a[i]==0 :
        dp[i]=1+min(i,k)+min(n-1-i,k)
    else:
        if not ((a[i]+k) < i-k ):
            # print(1 + min(i, k) + min(n-1 - i, k)+dp[a[i]-1])
            # print((min(min(i+k,n-1),min(a[i]-1+k,n-1)),max(min(i-k,0),min(a[i]-1-k,0)),1))
            dp[i] = 1 + min(i, k) + min(n -i-1, k)+dp[a[i]-1]- (min(min(i+k,n-1),min(a[i]-1+k,n-1))-max(max(i-k,0),max(a[i]-1-k,0))+1)
        else:
            dp[i] = 1 + min(i, k) + min(n - i, k) + dp[a[i] - 1]
print(*dp)