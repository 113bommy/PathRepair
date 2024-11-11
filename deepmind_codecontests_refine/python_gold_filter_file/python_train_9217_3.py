from sys import stdin,stdout
for _ in range(1):
    n=int(stdin.readline())
    a=list(map(int,stdin.readline().split()))
    if n==1:
        if a[0]==0:print(1)
        else:print(0)
        exit(0)
    dp=[[0 for _ in range(3)]for _ in range(n)]
    if a[0]==1 or a[0]==2:
        dp[0][a[0]]=1
    if a[0]==3:
        dp[0][1]=dp[0][2]=1
    if a[1]==0:
        i=1
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2])
    if a[1]==1:
        dp[1][1]=1+dp[0][2]
    if a[1]==2:
        dp[1][2]=1+dp[0][1]
    if a[1]==3:
        dp[1][1] = 1 + dp[0][2]
        dp[1][2] = 1 + dp[0][1]
    for i in range(2,n):
        if a[i]==0:
            dp[i][0]=max(dp[i-1][0],dp[i-1][1],dp[i-1][2])
        elif a[i]==1:
            dp[i][1]=1+max(dp[i-1][0],dp[i-1][2],dp[i-2][0],dp[i-2][1],dp[i-2][2])
        elif a[i]==2:
            dp[i][2]=1+max(dp[i-1][0],dp[i-1][1],dp[i-2][0],dp[i-2][1],dp[i-2][2])
        elif a[i]==3:
            dp[i][1] = 1 + max(dp[i - 1][0], dp[i - 1][2], dp[i - 2][0], dp[i - 2][1], dp[i - 2][2])
            dp[i][2]=1+max(dp[i-1][0],dp[i-1][1],dp[i-2][0],dp[i-2][1],dp[i-2][2])
    #print(*dp,sep='\n')
    print(n-max(dp[n-1][0],dp[n-1][1],dp[n-1][2]))