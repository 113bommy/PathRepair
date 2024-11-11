n,m,k=map(int,input().split())
arr=list(map(int,input().split()))
offer=[list(map(int,input().split())) for _ in range(m)]
arr=sorted(arr)
arr=arr[:k]
arr=arr[::-1]
acum=[0]
for i in range(k):
    acum.append(acum[-1]+arr[i])
dp=[acum[i] for i in range(k+1)]
for x,y in offer:
    if x>k:
        continue
    for i in range(x,k+1):
        dp[i]=min(dp[i],dp[i-x]+(acum[i]-acum[i-x])-(acum[i]-acum[i-y]))
    tmp=dp[0]
    for i in range(1,k+1):
        tmp=min(tmp,dp[i-1])+arr[i-1]
        dp[i]=min(dp[i],tmp)
for x,y in offer:
    if x>k:
        continue
    for i in range(x,k+1):
        dp[i]=min(dp[i],dp[i-x]+(acum[i]-acum[i-x])-(acum[i]-acum[i-y]))
    tmp=dp[0]
    for i in range(1,k+1):
        tmp=min(tmp,dp[i-1])+arr[i-1]
        dp[i]=min(dp[i],tmp)
print(dp[k])