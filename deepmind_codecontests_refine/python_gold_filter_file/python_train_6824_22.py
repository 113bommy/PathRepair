n = int(input())
cost = [int(x) for x in input().split()]
arr = []
for i in range(n):
    s = input()
    arr.append(s)
dp = [[-1,-1] for i in range(n)]
dp[0][0] = 0
dp[0][1] = cost[0]
# Two Cases
for i in range(1,n):
    # First -> Try to insert same string
    if(dp[i-1][0]!=-1):
        if(arr[i] >= arr[i-1]):
            dp[i][0] = dp[i-1][0]
    if(dp[i-1][1]!=-1):
        if(arr[i] >= arr[i-1][::-1]):
            if(dp[i][0] == -1):
                dp[i][0] = dp[i-1][1]
            else:
                dp[i][0] = min(dp[i][0], dp[i-1][1])
    # Second Case -> reversed string
    s = arr[i][::-1]
    if(dp[i-1][0]!=-1):
        if(s >= arr[i-1]):
            dp[i][1] = dp[i-1][0] + cost[i]
    if(dp[i-1][1]!=-1):
        if(s >= arr[i-1][::-1]):
            if(dp[i][1] == -1):
                dp[i][1] = dp[i-1][1] + cost[i]
            else:
                dp[i][1] = min(dp[i][1], dp[i-1][1] + cost[i])        
if(dp[-1][0] == -1 and dp[-1][1] == -1):
    print(-1)
elif(dp[-1][0] == -1 or dp[-1][1] == -1):
    print(max(dp[-1][0], dp[-1][1]))
else:
    print(min(dp[-1][0], dp[-1][1])) 