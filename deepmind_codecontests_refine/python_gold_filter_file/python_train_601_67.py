def main():
    n,m=map(int,input().split())
    s=list(map(int,input().split()))
    t=list(map(int,input().split()))
    dp=[[0]*(m+1) for _ in [0]*(n+1)]
    for i in range(n+1):
        dp[i][m]=1
    for i in range(m+1):
        dp[n][i]=1
    for i in range(n-1,-1,-1):
        for j in range(m-1,-1,-1):
            dp[i][j]=(dp[i+1][j]+dp[i][j+1]-(s[i]!=t[j])*dp[i+1][j+1])%(10**9+7)
    print(dp[0][0])
main()
