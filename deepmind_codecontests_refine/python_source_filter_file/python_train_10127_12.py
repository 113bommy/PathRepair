for i in range(int(input())):
    n,q= map(int,input().split())
    a=[int(x) for x in input().split()]
    dp= [0 for j in range(n+1) ]
    dp12 = [0 for j in range(n+1)]
    x,y = 0,0
    for j in range(1,n+1):
        dp[j] = x + a[i-1]
        dp12[j] = y - a[i-1]
        x=max(x,dp[j])
        y= max(dp12[j],y)
    print(max(x,y))