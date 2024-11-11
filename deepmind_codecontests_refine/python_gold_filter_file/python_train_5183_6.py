n=int(input())
a=list(map(int,input().split()))
if n%2==1:
    dp=[[0 for j in range(3)] for i in range(n//2)]
    dp[0][0]=a[0]
    dp[0][1]=a[1]
    dp[0][2]=a[2]
    for i in range(n//2-1):
        dp[i+1][0]=(dp[i][0]+a[2*(i+1)])
        dp[i+1][1]=max(dp[i][0],dp[i][1])+a[2*(i+1)+1]
        dp[i+1][2]=max(dp[i])+a[2*(i+1)+2]
    print(max(dp[-1]))
if n%2==0:
    dp=[[0 for j in range(2)] for i in range(n//2)]
    dp[0][0]=a[0]
    dp[0][1]=a[1]
    for i in range(n//2-1):
        dp[i+1][0]=(dp[i][0]+a[2*(i+1)])
        dp[i+1][1]=max(dp[i][0],dp[i][1])+a[2*(i+1)+1]
        #dp[i+1][2]=max(dp[i])+a[2*(i+2)+2]
    print(max(dp[-1]))   
