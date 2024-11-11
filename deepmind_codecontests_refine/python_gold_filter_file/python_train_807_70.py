def slove(n, a_list):

    dp = [[0]*(n+1) for i in range(n+1)]
    for i in range(n):
        for j in range(n-i):
            dp[i+1][j] = max(dp[i+1][j],
                         dp[i][j]+a_list[i+j][0]*abs(a_list[i+j][1]-i))
            dp[i][j+1] = max(dp[i][j+1],
                         dp[i][j]+a_list[i+j][0]*abs((n-1-j)-a_list[i+j][1]))

    return max([max(i) for i in dp])

if __name__ == "__main__":
    n = int(input())
    k = sorted([(int(x),i) for i,x in enumerate(input().split())], reverse=True)
    print(slove(n, k))
