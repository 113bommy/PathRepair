n=int(input())
arr=list(map(int,input().split()))
stackgre=[0]
stackless=[0]
dp=[0]*n
dp[0]=0
for i in range(1,n):
    dp[i]=dp[i-1]+1
    while(stackless and arr[stackless[-1]]>arr[i]):
        c=arr[stackless[-1]]
        stackless.pop()
        if arr[i]<c and stackless:
            dp[i]=min(dp[stackless[-1]]+1,dp[i])
    while(stackgre and arr[stackgre[-1]]<arr[i]):
        c=arr[stackgre[-1]]
        stackgre.pop()
        if arr[i]>c and stackgre:
            dp[i]=min(dp[stackgre[-1]]+1,dp[i])

    stackgre.append(i)
    stackless.append(i)

print(dp[-1])
